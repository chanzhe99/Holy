// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UArrayBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class HOLY_API UUArrayBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)

	static void QuickSort();
};
