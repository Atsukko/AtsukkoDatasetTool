// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AtsukkoDatasetToolPlugin/Public/RecordCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRecordCharacter() {}
// Cross Module References
	ATSUKKODATASETTOOLPLUGIN_API UClass* Z_Construct_UClass_ARecordCharacter();
	ATSUKKODATASETTOOLPLUGIN_API UClass* Z_Construct_UClass_ARecordCharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UAnimationAsset_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimSequence_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	UPackage* Z_Construct_UPackage__Script_AtsukkoDatasetToolPlugin();
// End Cross Module References
	DEFINE_FUNCTION(ARecordCharacter::execIsPlayingFinished)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsPlayingFinished();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ARecordCharacter::execGetAnimationsPendingPlay)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_SKMeshName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UAnimSequence*>*)Z_Param__Result=P_THIS->GetAnimationsPendingPlay(Z_Param_SKMeshName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ARecordCharacter::execHandleAnimationAutoplay)
	{
		P_GET_TARRAY_REF(UAnimationAsset*,Z_Param_Out_AnimationsPendingPlay);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleAnimationAutoplay(Z_Param_Out_AnimationsPendingPlay);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ARecordCharacter::execLabelOneFrame)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Timer);
		P_GET_PROPERTY(FStrProperty,Z_Param_SKMeshName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LabelOneFrame(Z_Param_Out_Timer,Z_Param_SKMeshName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ARecordCharacter::execSetResolution)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetResolution();
		P_NATIVE_END;
	}
	void ARecordCharacter::StaticRegisterNativesARecordCharacter()
	{
		UClass* Class = ARecordCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAnimationsPendingPlay", &ARecordCharacter::execGetAnimationsPendingPlay },
			{ "HandleAnimationAutoplay", &ARecordCharacter::execHandleAnimationAutoplay },
			{ "IsPlayingFinished", &ARecordCharacter::execIsPlayingFinished },
			{ "LabelOneFrame", &ARecordCharacter::execLabelOneFrame },
			{ "SetResolution", &ARecordCharacter::execSetResolution },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics
	{
		struct RecordCharacter_eventGetAnimationsPendingPlay_Parms
		{
			FString SKMeshName;
			TArray<UAnimSequence*> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SKMeshName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SKMeshName;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::NewProp_SKMeshName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::NewProp_SKMeshName = { "SKMeshName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecordCharacter_eventGetAnimationsPendingPlay_Parms, SKMeshName), METADATA_PARAMS(Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::NewProp_SKMeshName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::NewProp_SKMeshName_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_UAnimSequence_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecordCharacter_eventGetAnimationsPendingPlay_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::NewProp_SKMeshName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** \n\x09 * Function to get the array to store all the animations of curren SKMesh ought to be played, called in blueprint.\n\x09 * \n\x09 * @param SKMeshName Display name of skeleton mesh.\n\x09 * @return The array to store all the animations of curren SKMesh ought to be played. \n\x09 * @author Atsukko\n\x09 */" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
		{ "ToolTip", "Function to get the array to store all the animations of curren SKMesh ought to be played, called in blueprint.\n\n@param SKMeshName Display name of skeleton mesh.\n@return The array to store all the animations of curren SKMesh ought to be played.\n@author Atsukko" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARecordCharacter, nullptr, "GetAnimationsPendingPlay", nullptr, nullptr, sizeof(Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::RecordCharacter_eventGetAnimationsPendingPlay_Parms), Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics
	{
		struct RecordCharacter_eventHandleAnimationAutoplay_Parms
		{
			TArray<UAnimationAsset*> AnimationsPendingPlay;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimationsPendingPlay_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimationsPendingPlay_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AnimationsPendingPlay;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::NewProp_AnimationsPendingPlay_Inner = { "AnimationsPendingPlay", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_UAnimationAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::NewProp_AnimationsPendingPlay_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::NewProp_AnimationsPendingPlay = { "AnimationsPendingPlay", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecordCharacter_eventHandleAnimationAutoplay_Parms, AnimationsPendingPlay), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::NewProp_AnimationsPendingPlay_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::NewProp_AnimationsPendingPlay_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::NewProp_AnimationsPendingPlay_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::NewProp_AnimationsPendingPlay,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** \n\x09 * Function to handle the animations autoplay, called in blueprint.\n\x09 * \n\x09 * @param AnimationsPendingPlay The array to store all the animations of curren SKMesh ought to be played.\n\x09 * @return \n\x09 * @author Atsukko\n\x09 */" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
		{ "ToolTip", "Function to handle the animations autoplay, called in blueprint.\n\n@param AnimationsPendingPlay The array to store all the animations of curren SKMesh ought to be played.\n@return\n@author Atsukko" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARecordCharacter, nullptr, "HandleAnimationAutoplay", nullptr, nullptr, sizeof(Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::RecordCharacter_eventHandleAnimationAutoplay_Parms), Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics
	{
		struct RecordCharacter_eventIsPlayingFinished_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((RecordCharacter_eventIsPlayingFinished_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(RecordCharacter_eventIsPlayingFinished_Parms), &Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARecordCharacter, nullptr, "IsPlayingFinished", nullptr, nullptr, sizeof(Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::RecordCharacter_eventIsPlayingFinished_Parms), Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics
	{
		struct RecordCharacter_eventLabelOneFrame_Parms
		{
			float Timer;
			FString SKMeshName;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Timer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Timer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SKMeshName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SKMeshName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_Timer_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_Timer = { "Timer", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecordCharacter_eventLabelOneFrame_Parms, Timer), METADATA_PARAMS(Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_Timer_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_Timer_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_SKMeshName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_SKMeshName = { "SKMeshName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecordCharacter_eventLabelOneFrame_Parms, SKMeshName), METADATA_PARAMS(Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_SKMeshName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_SKMeshName_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_Timer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::NewProp_SKMeshName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** \n\x09 * Main function to record information of one frame, called in blueprint.\n\x09 * \n\x09 * @param Timer Recording timer.\n\x09 * @param SKMeshName Display name of skeleton mesh.\n\x09 * @return \n\x09 * @author Atsukko\n\x09 */" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
		{ "ToolTip", "Main function to record information of one frame, called in blueprint.\n\n@param Timer Recording timer.\n@param SKMeshName Display name of skeleton mesh.\n@return\n@author Atsukko" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARecordCharacter, nullptr, "LabelOneFrame", nullptr, nullptr, sizeof(Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::RecordCharacter_eventLabelOneFrame_Parms), Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARecordCharacter_LabelOneFrame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ARecordCharacter_LabelOneFrame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ARecordCharacter_SetResolution_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ARecordCharacter_SetResolution_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** \n\x09 * Set window resolution, which is also image size.\n\x09 * \n\x09 * @param \n\x09 * @return \n\x09 * @author Atsukko\n\x09 */" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
		{ "ToolTip", "Set window resolution, which is also image size.\n\n@param\n@return\n@author Atsukko" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ARecordCharacter_SetResolution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARecordCharacter, nullptr, "SetResolution", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ARecordCharacter_SetResolution_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ARecordCharacter_SetResolution_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ARecordCharacter_SetResolution()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ARecordCharacter_SetResolution_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARecordCharacter);
	UClass* Z_Construct_UClass_ARecordCharacter_NoRegister()
	{
		return ARecordCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ARecordCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SKMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SKMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPlayingFinished_MetaData[];
#endif
		static void NewProp_bPlayingFinished_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlayingFinished;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageSize_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ImageSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DatasetDir_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DatasetDir;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARecordCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_AtsukkoDatasetToolPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ARecordCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ARecordCharacter_GetAnimationsPendingPlay, "GetAnimationsPendingPlay" }, // 1127682041
		{ &Z_Construct_UFunction_ARecordCharacter_HandleAnimationAutoplay, "HandleAnimationAutoplay" }, // 3135830773
		{ &Z_Construct_UFunction_ARecordCharacter_IsPlayingFinished, "IsPlayingFinished" }, // 1662311524
		{ &Z_Construct_UFunction_ARecordCharacter_LabelOneFrame, "LabelOneFrame" }, // 3991110057
		{ &Z_Construct_UFunction_ARecordCharacter_SetResolution, "SetResolution" }, // 2617249491
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "RecordCharacter.h" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCharacter_Statics::NewProp_SKMeshComponent_MetaData[] = {
		{ "Category", "RecordCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARecordCharacter_Statics::NewProp_SKMeshComponent = { "SKMeshComponent", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ARecordCharacter, SKMeshComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_SKMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_SKMeshComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCharacter_Statics::NewProp_bPlayingFinished_MetaData[] = {
		{ "BlueprintGetter", "IsPlayingFinished" },
		{ "Category", "RecordCharacter" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ARecordCharacter_Statics::NewProp_bPlayingFinished_SetBit(void* Obj)
	{
		((ARecordCharacter*)Obj)->bPlayingFinished = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ARecordCharacter_Statics::NewProp_bPlayingFinished = { "bPlayingFinished", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ARecordCharacter), &Z_Construct_UClass_ARecordCharacter_Statics::NewProp_bPlayingFinished_SetBit, METADATA_PARAMS(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_bPlayingFinished_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_bPlayingFinished_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCharacter_Statics::NewProp_ImageSize_MetaData[] = {
		{ "Category", "RecordCharacter" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ARecordCharacter_Statics::NewProp_ImageSize = { "ImageSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ARecordCharacter, ImageSize), METADATA_PARAMS(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_ImageSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_ImageSize_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DatasetDir_MetaData[] = {
		{ "Category", "RecordCharacter" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DatasetDir = { "DatasetDir", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ARecordCharacter, DatasetDir), METADATA_PARAMS(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DatasetDir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DatasetDir_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCharacter_Statics::NewProp_PlayRate_MetaData[] = {
		{ "Category", "RecordCharacter" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARecordCharacter_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ARecordCharacter, PlayRate), METADATA_PARAMS(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_PlayRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_PlayRate_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** MappingContext */" },
		{ "ModuleRelativePath", "Public/RecordCharacter.h" },
		{ "ToolTip", "MappingContext" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ARecordCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DefaultMappingContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DefaultMappingContext_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARecordCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCharacter_Statics::NewProp_SKMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCharacter_Statics::NewProp_bPlayingFinished,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCharacter_Statics::NewProp_ImageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DatasetDir,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCharacter_Statics::NewProp_PlayRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARecordCharacter_Statics::NewProp_DefaultMappingContext,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARecordCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARecordCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARecordCharacter_Statics::ClassParams = {
		&ARecordCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ARecordCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ARecordCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARecordCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARecordCharacter()
	{
		if (!Z_Registration_Info_UClass_ARecordCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARecordCharacter.OuterSingleton, Z_Construct_UClass_ARecordCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARecordCharacter.OuterSingleton;
	}
	template<> ATSUKKODATASETTOOLPLUGIN_API UClass* StaticClass<ARecordCharacter>()
	{
		return ARecordCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARecordCharacter);
	ARecordCharacter::~ARecordCharacter() {}
	struct Z_CompiledInDeferFile_FID_AtsukkoDatasetTool_Plugins_AtsukkoDatasetToolPlugin_Source_AtsukkoDatasetToolPlugin_Public_RecordCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AtsukkoDatasetTool_Plugins_AtsukkoDatasetToolPlugin_Source_AtsukkoDatasetToolPlugin_Public_RecordCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARecordCharacter, ARecordCharacter::StaticClass, TEXT("ARecordCharacter"), &Z_Registration_Info_UClass_ARecordCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARecordCharacter), 1554088799U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_AtsukkoDatasetTool_Plugins_AtsukkoDatasetToolPlugin_Source_AtsukkoDatasetToolPlugin_Public_RecordCharacter_h_2551553153(TEXT("/Script/AtsukkoDatasetToolPlugin"),
		Z_CompiledInDeferFile_FID_AtsukkoDatasetTool_Plugins_AtsukkoDatasetToolPlugin_Source_AtsukkoDatasetToolPlugin_Public_RecordCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_AtsukkoDatasetTool_Plugins_AtsukkoDatasetToolPlugin_Source_AtsukkoDatasetToolPlugin_Public_RecordCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
