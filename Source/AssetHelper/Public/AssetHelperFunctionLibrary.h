// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssetHelperFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ASSETHELPER_API UAssetHelperFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static int32 CalculateTextureCRC(UTexture2D* Texture2D)
	{
		uint32 Result;
		return Texture2D->GetSourceArtCRC(Result) ? Result : -1;
	}
};
