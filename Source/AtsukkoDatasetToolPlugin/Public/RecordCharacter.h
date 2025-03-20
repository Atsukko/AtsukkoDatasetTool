#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RecordCharacter.generated.h"

UCLASS()
class ATSUKKODATASETTOOLPLUGIN_API ARecordCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARecordCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Get the screenshot command string, called by LabelOneFrame */
	FString GetScreenShotCommand(const float& Timer, const FString& SKMeshName, const int32& ImageSizeX, const int32& ImageSizeY);
	/** Save the label file to disk, called by LabelOneFrame */
	void SaveLabelFile(const float& Timer, const FString& SKMeshName, const TArray<FVector>& RelativeJointPositions);
	/** Save the 2D label file to disk, called by LabelOneFrame */
	TArray<FVector2D> Save2DLabelFile(const float& Timer, const FString& SKMeshName, const TArray<FVector>& JointPositions);

	/** Visibility related */
	void SaveVisibilityFile(const float& Timer, const FString& SKMeshName, const TArray<FVector>& JointPositions, const TArray<FVector2D>& JointPositions2D);
	float GetDistanceVisibility(const float& Distance, const float& Depth);
	float GetHipVisibility(const FVector2D& JointPos2D, const FVector2D& LeftHipPos2D, const FVector2D& RightHipPos2D);

	/** 
	 * Update the valid folder name to store data of this SKMesh, in case naming conflict. 
	 * 
	 * @param SKMeshName Display name of skeleton mesh.
	 * @return 
	 * @author Atsukko
	 */
	void UpdateValidFolderName(const FString& SKMeshName);

	/** 
	 * Set window resolution, which is also image size.
	 * 
	 * @param 
	 * @return 
	 * @author Atsukko
	 */
	UFUNCTION(BlueprintCallable)
	void SetResolution();

	/** 
	 * Main function to record information of one frame, called in blueprint.
	 * 
	 * @param Timer Recording timer.
	 * @param SKMeshName Display name of skeleton mesh.
	 * @return 
	 * @author Atsukko
	 */
	UFUNCTION(BlueprintCallable)
	void LabelOneFrame(const float& Timer, const FString& SKMeshName);


	/** 
	 * Function to handle the animations autoplay, called in blueprint.
	 * 
	 * @param AnimationsPendingPlay The array to store all the animations of curren SKMesh ought to be played.
	 * @return 
	 * @author Atsukko
	 */
	UFUNCTION(BlueprintCallable)
	void HandleAnimationAutoplay(const TArray<UAnimationAsset*>& AnimationsPendingPlay);

	/** 
	 * Function to get the array to store all the animations of curren SKMesh ought to be played, called in blueprint.
	 * 
	 * @param SKMeshName Display name of skeleton mesh.
	 * @return The array to store all the animations of curren SKMesh ought to be played. 
	 * @author Atsukko
	 */
	UFUNCTION(BlueprintCallable)
	TArray<UAnimSequence*> GetAnimationsPendingPlay(const FString& SKMeshName);

private:

	int32 CurPlayingAnimationInd = 0;

	FString ValidFolderName;

	bool bFirstCapture = true;

public:
	UPROPERTY(BlueprintReadWrite)
	USkeletalMeshComponent* SKMeshComponent;
	
	UPROPERTY(BlueprintGetter = IsPlayingFinished)
	bool bPlayingFinished = false;
	UFUNCTION(BlueprintGetter)
	bool IsPlayingFinished() const {return bPlayingFinished;}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ImageSize = 460;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString DatasetDir = "D:/Unreal/projects/AtsukkoDatasetTool/Plugins/AtsukkoDatasetToolPlugin/Content/Dataset/data/";

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
};

