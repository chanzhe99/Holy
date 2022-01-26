// Copyright Pizza Masters 5, All Rights Reserved.

#pragma once

//! Engine Required Core
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Containers/Array.h"
#include <iostream>

#include "UArrayBlueprintLibrary.generated.h"

UCLASS()
class HOLY_API UUArrayBlueprintLibrary : public UObject
{
	GENERATED_BODY()

private:
	template<typename T>
	static void Swap(T* a, T* b)
	{
		T t = *a;
		*a = *b;
		*b = t;
	}

	template <typename T>
	static int Partition(TArray<T>& array, int low, int high)
	{
		T pivot = array[high];
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++)
		{
			if (array[j] < pivot)
			{
				i++;
				Swap(&array[i], &array[j]);
			}
		}

		Swap(&array[i + 1], &array[high]);
		return (i + 1);
	}

	template<typename T>
	static void QuickSort(const TArray<T>& inArray, TArray<T>& outArray, int low, int high)
	{
		constexpr bool IsANumber = std::is_integral<T>::value || std::is_floating_point<T>::value;
		static_assert(IsANumber, "T is not a numeric type.");

		if (low < high)
		{
			int partitionIndex = Partition<T>(outArray, low, high);
			QuickSort<T>(inArray, outArray, low, partitionIndex - 1);
			QuickSort<T>(inArray, outArray, partitionIndex + 1, high);
		}
	}

public:

	UFUNCTION(BlueprintCallable)
	static void Evil(int hello)
	{
	}

	UFUNCTION(BlueprintCallable)
	static void QuickSort(const TArray<float>& inArray, TArray<float>& outArray)
	{
		TArray<float> array = TArray<float>();
		outArray = array;
		QuickSort<float>(inArray, outArray, 0, inArray.Num() - 1);
	}
};
