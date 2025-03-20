// Fill out your copyright notice in the Description page of Project Settings.


#include "RecordCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"

#define Foot_X_VISIBILITY_LIMIT 0.1

constexpr double STANDARD_DIST = 88.63617;
constexpr double UNVISIBLE_LIMIT = 0.042373;
constexpr double VISIBLE_LIMIT = 0.070622;
constexpr double CORRECTION_FACTOR = 0.053655;
constexpr double DIVISOR = (VISIBLE_LIMIT - UNVISIBLE_LIMIT) / (CORRECTION_FACTOR - UNVISIBLE_LIMIT);

ARecordCharacter::ARecordCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SKMeshComponent = Cast<USkeletalMeshComponent>(GetComponentByClass(UMeshComponent::StaticClass()));

}

void ARecordCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ARecordCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ARecordCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FString ARecordCharacter::GetScreenShotCommand(const float& Timer, const FString& SKMeshName, const int32& ImageSizeX, const int32& ImageSizeY)
{
	//FString Command(TEXT("HighResShot filename=\"C:/Atsukko/UE/UE_Projects/HPE_DataSetTool/Dataset/"));
	FString Command(FString(TEXT("HighResShot filename=\"")) + DatasetDir);
	FString ImgSize = FString::FromInt(ImageSizeX) + "x" + FString::FromInt(ImageSizeY);

	FString PathName = DatasetDir + SKMeshName + TEXT("/images/");
	FString FileName = FString::SanitizeFloat(Timer) + TEXT(".png");

	return FPaths::Combine(PathName, FileName);
}

void ARecordCharacter::SaveLabelFile(const float& Timer, const FString& SKMeshName, const TArray<FVector>& RelativeJointPositions)
{
	
	UE_LOG(LogTemp, Display, TEXT("SaveLabelFile"));
	TArray<FString> OutputStrArray;
	for (auto JointPosition : RelativeJointPositions)
	{
		FString JointRelativePosString = FString::SanitizeFloat(JointPosition.X) + " " + FString::SanitizeFloat(JointPosition.Y) + " " + FString::SanitizeFloat(JointPosition.Z);
		OutputStrArray.Add(JointRelativePosString);
	}

	FString OutputPath = DatasetDir + SKMeshName + TEXT("/labels/") + FString::SanitizeFloat(Timer) + TEXT(".txt");
	
	FFileHelper::SaveStringArrayToFile(OutputStrArray, *OutputPath);
}

TArray<FVector2D> ARecordCharacter::Save2DLabelFile(const float& Timer, const FString& SKMeshName, const TArray<FVector>& JointPositions)
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();

	FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(this);
	//FVector2D ViewportSize;
	//GEngine->GameViewport->GetViewportSize(ViewportSize);
	
	TArray<FVector2D> JointPositions2D;
	TArray<FString> OutputStrArray;
	for (auto JointPosition : JointPositions)
	{
		FVector2D ScreenPos;
		bool bJointScreenPos = UGameplayStatics::ProjectWorldToScreen(PC, JointPosition, ScreenPos);
		JointPositions2D.Add(ScreenPos);
		
		FString JointScreenPosString = FString::SanitizeFloat(ScreenPos.X / ViewportSize.X) + " " + FString::SanitizeFloat(ScreenPos.Y / ViewportSize.Y);
		OutputStrArray.Add(JointScreenPosString);
		
	}
	FString OutputPath = DatasetDir + SKMeshName + TEXT("/labels_2d/") + FString::SanitizeFloat(Timer) + TEXT(".txt");

	FFileHelper::SaveStringArrayToFile(OutputStrArray, *OutputPath);

	return JointPositions2D;
}

void ARecordCharacter::SaveVisibilityFile(const float& Timer, const FString& SKMeshName, const TArray<FVector>& JointPositions, const TArray<FVector2D>& JointPositions2D)
{
	return;
	
	FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(this);
	//FVector2D ViewportSize;
	//GEngine->GameViewport->GetViewportSize(ViewportSize);
	// **************脚部关节可见性
	
	// *******脚部关节的帧可见性
	float LeftVisibility0 = 1.f;
	float RightVisibility0 = 1.f;
	if(JointPositions2D[4].X > ViewportSize.X || JointPositions2D[4].X < 0 || JointPositions2D[4].Y > ViewportSize.Y || JointPositions2D[4].Y < 0) LeftVisibility0 = 0.f;
	if(JointPositions2D[5].X > ViewportSize.X || JointPositions2D[5].X < 0|| JointPositions2D[5].Y > ViewportSize.Y || JointPositions2D[5].Y < 0) RightVisibility0 = 0.f;
	
	// *******脚部关节相对同侧大腿的可见性
	// 计算髋骨到脚关节向量到大腿骨骼向量投影向量的长度系数
	float LeftDistance = 0.f; 
	float RightDistance = 0.f; 
	FVector2D LeftBoneVec2D = JointPositions2D[2] - JointPositions2D[0];
	FVector2D RightBoneVec2D = JointPositions2D[3] - JointPositions2D[1];
	FVector2D LeftHip2FootVec2D = JointPositions2D[4] - JointPositions2D[0];
	FVector2D RightHip2FootVec2D = JointPositions2D[5] - JointPositions2D[1];
	float LeftProjectionFactor = LeftBoneVec2D.Dot(LeftHip2FootVec2D) / FMath::Square(LeftBoneVec2D.Length());
	float RightProjectionFactor = RightBoneVec2D.Dot(RightHip2FootVec2D) / FMath::Square(RightBoneVec2D.Length());
	
	// 计算脚部关节距离可见性
	float LeftVisibility1 = 0.f;
	float RightVisibility1 = 0.f;
	float LeftDepth = -(JointPositions[0].X + JointPositions[2].X) / 2.f;
	float RightDepth = -(JointPositions[1].X + JointPositions[3].X) / 2.f;
	
	if(LeftProjectionFactor > 0)
	{
		if(LeftProjectionFactor >= 1) LeftDistance = (JointPositions2D[4] - JointPositions2D[2]).Length() / ViewportSize.X;
		else LeftDistance = (LeftBoneVec2D * LeftProjectionFactor - LeftHip2FootVec2D).Length() / ViewportSize.X;

		LeftVisibility1 = GetDistanceVisibility(LeftDistance, LeftDepth);
		if(!FMath::IsNearlyEqual(LeftVisibility1, 0.f) && !FMath::IsNearlyEqual(LeftVisibility1, 1.f))
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Hey!");
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::SanitizeFloat(Timer));
		}
	}
	if(RightProjectionFactor >= 0)
	{
		if(RightProjectionFactor >= 1) RightDistance = (JointPositions2D[5] - JointPositions2D[3]).Length() / ViewportSize.X;
		else RightDistance = (RightBoneVec2D * RightProjectionFactor - RightHip2FootVec2D).Length() / ViewportSize.X;

		RightVisibility1 = GetDistanceVisibility(RightDistance, RightDepth);
	}


	// *******脚部关节相对髋骨的可见性
	float LeftVisibility2 = GetHipVisibility(JointPositions2D[4], JointPositions2D[0], JointPositions2D[1]);
	float RightVisibility2 = GetHipVisibility(JointPositions2D[5], JointPositions2D[0], JointPositions2D[1]);

	
	// *******脚部关节总可见性
	float LeftVisibility = LeftVisibility0 * LeftVisibility1 * LeftVisibility2;
	float RightVisibility = RightVisibility0 * RightVisibility1 * RightVisibility2;

	// **************膝盖关节可见性
	float LeftKneeVisibility = 0.f;
	float RightKneeVisibility = 0.f;

	float LeftKneeDistance = (JointPositions2D[2] - JointPositions2D[0]).Length() / ViewportSize.X;
	float RightKneeDistance = (JointPositions2D[3] - JointPositions2D[1]).Length() / ViewportSize.X;
	float LeftHipDepth = -JointPositions[0].X;
	float RightHipDepth = -JointPositions[1].X;

	LeftKneeVisibility = GetDistanceVisibility(LeftKneeDistance, LeftHipDepth) * GetHipVisibility(JointPositions2D[2], JointPositions2D[0], JointPositions2D[1]);
	RightKneeVisibility = GetDistanceVisibility(RightKneeDistance, RightHipDepth) * GetHipVisibility(JointPositions2D[3], JointPositions2D[0], JointPositions2D[1]);

	if(JointPositions2D[2].X > ViewportSize.X || JointPositions2D[2].X < 0 || JointPositions2D[2].Y > ViewportSize.Y || JointPositions2D[2].Y < 0) LeftKneeVisibility = 0.f;
	if(JointPositions2D[3].X > ViewportSize.X || JointPositions2D[3].X < 0 || JointPositions2D[3].Y > ViewportSize.Y || JointPositions2D[3].Y < 0) RightKneeVisibility = 0.f;
	
	// **************髋关节可见性
	float LeftHipVisibility = 1.f;
	float RightHipVisibility = 1.f;
	if(JointPositions2D[0].X > ViewportSize.X || JointPositions2D[0].X < 0 || JointPositions2D[0].Y > ViewportSize.Y || JointPositions2D[0].Y < 0) LeftHipVisibility = 0.f;
	if(JointPositions2D[1].X > ViewportSize.X || JointPositions2D[1].X < 0 || JointPositions2D[1].Y > ViewportSize.Y || JointPositions2D[1].Y < 0) RightHipVisibility = 0.f;

	// **************存盘
	TArray<FString> OutputStrArray;
	OutputStrArray.Add(FString::SanitizeFloat(LeftHipVisibility));
	OutputStrArray.Add(FString::SanitizeFloat(RightHipVisibility));
	OutputStrArray.Add(FString::SanitizeFloat(LeftKneeVisibility));
	OutputStrArray.Add(FString::SanitizeFloat(RightKneeVisibility));
	OutputStrArray.Add(FString::SanitizeFloat(LeftVisibility));
	OutputStrArray.Add(FString::SanitizeFloat(RightVisibility));
	
	FString OutputPath = DatasetDir + SKMeshName + TEXT("/visibility/") + FString::SanitizeFloat(Timer) + TEXT(".txt");

	FFileHelper::SaveStringArrayToFile(OutputStrArray, *OutputPath);
	
}

float ARecordCharacter::GetDistanceVisibility(const float& Distance, const float& Depth)
{
	float Visibility = 0.f;
	if(Distance > (DIVISOR + STANDARD_DIST * UNVISIBLE_LIMIT) / Depth) Visibility = 1.f;
	else if(Distance < STANDARD_DIST * UNVISIBLE_LIMIT / Depth) Visibility = 0.f;
	else Visibility = 1.f - FMath::Square((Distance * Depth - STANDARD_DIST * UNVISIBLE_LIMIT) / DIVISOR - 1);
	
	return Visibility;
}

float ARecordCharacter::GetHipVisibility(const FVector2D& JointPos2D, const FVector2D& LeftHipPos2D,
	const FVector2D& RightHipPos2D)
{
	FVector2D HipVec = RightHipPos2D - LeftHipPos2D;
	FVector2D HipToJointVec = JointPos2D - LeftHipPos2D;

	FVector CrossRes = FVector::CrossProduct(FVector(HipVec.X, HipVec.Y, 0.f),
	                                                           FVector(HipToJointVec.X, HipToJointVec.Y, 0.f));
	
	if(CrossRes.Z > 0.f) return 0.f;
	return 1.f;
}

void ARecordCharacter::UpdateValidFolderName(const FString& SKMeshName)
{
	if(bFirstCapture)
	{
		ValidFolderName = SKMeshName;
		int32 CurInd = 1;
		bFirstCapture = false;
		while(FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*(DatasetDir + ValidFolderName)))
		{
			ValidFolderName = SKMeshName + FString::FromInt(CurInd);
			CurInd++;
		}
	}
}

void ARecordCharacter::SetResolution()
{
	GEngine->GetGameUserSettings()->SetFullscreenMode(EWindowMode::Type::Windowed);
	GEngine->GetGameUserSettings()->SetScreenResolution(FIntPoint(ImageSize, ImageSize));
	GEngine->GetGameUserSettings()->ApplySettings(true);
}


void ARecordCharacter::LabelOneFrame(const float& Timer, const FString& SKMeshName)
{
	USkeletalMeshComponent* SKMesh = GetMesh();
	FVector HipLeftPos = SKMesh->GetSocketLocation(FName(TEXT("HipLeft")));
	FVector HipRightPos = SKMesh->GetSocketLocation(FName(TEXT("HipRight")));
	FVector KneeLeftPos = SKMesh->GetSocketLocation(FName(TEXT("KneeLeft")));
	FVector KneeRightPos = SKMesh->GetSocketLocation(FName(TEXT("KneeRight")));
	FVector FootLeftPos = SKMesh->GetSocketLocation(FName(TEXT("FootLeft")));
	FVector FootRightPos = SKMesh->GetSocketLocation(FName(TEXT("FootRight")));
	/*FVector HipPos = GetMesh()->GetSocketLocation(FName(TEXT("Hip")));
	FVector HandLeftPos = GetMesh()->GetSocketLocation(FName(TEXT("HandLeft")));
	FVector HandRightPos = GetMesh()->GetSocketLocation(FName(TEXT("HandRight")));
	FVector ElbowLeftPos = GetMesh()->GetSocketLocation(FName(TEXT("ElbowLeft")));
	FVector ElbowRightPos = GetMesh()->GetSocketLocation(FName(TEXT("ElbowRight")));
	FVector SpinePos = GetMesh()->GetSocketLocation(FName(TEXT("Spine")));*/
	TArray<FVector> JointPositions;
	JointPositions.Add(HipLeftPos);
	JointPositions.Add(HipRightPos);
	JointPositions.Add(KneeLeftPos);
	JointPositions.Add(KneeRightPos);
	JointPositions.Add(FootLeftPos);
	JointPositions.Add(FootRightPos);
	/*JointPositions.Add(HipPos);
	JointPositions.Add(HandLeftPos);
	JointPositions.Add(HandRightPos);
	JointPositions.Add(ElbowLeftPos);
	JointPositions.Add(ElbowRightPos);
	JointPositions.Add(SpinePos);*/

	FTransform CameraTransform = GetMesh()->GetSocketTransform(FName(TEXT("CameraSocket")));
	TArray<FVector> RelativeJointPositions;
	for (auto JointPosition : JointPositions)
	{
		FVector JointRelativePos = UKismetMathLibrary::InverseTransformLocation(CameraTransform, JointPosition);
		RelativeJointPositions.Add(JointRelativePos);
	}

	UpdateValidFolderName(SKMeshName);
	
	SaveLabelFile(Timer, ValidFolderName, RelativeJointPositions);
	TArray<FVector2D> JointPositions2D = Save2DLabelFile(Timer, ValidFolderName, JointPositions);
	SaveVisibilityFile(Timer, ValidFolderName, RelativeJointPositions, JointPositions2D);
	
	
	FScreenshotRequest::RequestScreenshot(GetScreenShotCommand(Timer, ValidFolderName, ImageSize, ImageSize), false, false);
}

void ARecordCharacter::HandleAnimationAutoplay(const TArray<UAnimationAsset*>& AnimationsPendingPlay)
{
	if(AnimationsPendingPlay.Num() == 0) return;
	if(++CurPlayingAnimationInd < AnimationsPendingPlay.Num())
	{
		SKMeshComponent->PlayAnimation(AnimationsPendingPlay[CurPlayingAnimationInd], false);
		SKMeshComponent->SetPlayRate(PlayRate);
	}
	else
	{
		bPlayingFinished = true;
	}
}

TArray<UAnimSequence*> ARecordCharacter::GetAnimationsPendingPlay(const FString& SKMeshName)
{
	int32 Count = 0;
	TArray<UAnimSequence*> AnimationsPendingPlay;
	FString AnimationsPath = FString(TEXT("/Game/AnimationsPendingPlay/")) + SKMeshName;
	TArray<FAssetData> AnimationsAssetData;

	IAssetRegistry& AssetRegistry = FModuleManager::Get().GetModulePtr<FAssetRegistryModule>("AssetRegistry")->Get();
	AssetRegistry.GetAssetsByPath(FName(*AnimationsPath), AnimationsAssetData);

	if(AnimationsAssetData.Num() == 0)
	{
		bPlayingFinished = true;
		return AnimationsPendingPlay;
	}
	
	for (const FAssetData& AssetData : AnimationsAssetData)
	{
		AnimationsPendingPlay.Add(Cast<UAnimSequence>(AssetData.GetAsset()));
		Count++;
	}

	if(Count != 0)
	{
		SKMeshComponent->PlayAnimation(AnimationsPendingPlay[0], false);
		SKMeshComponent->SetPlayRate(.1f);
	}
	return AnimationsPendingPlay;
}



