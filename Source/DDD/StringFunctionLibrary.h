#pragma once

class FStringFunctionLibrary
{
public:
	template <typename T>
	static inline FString EnumToString(T EnumValue)
	{
		const UEnum* EnumPtr = StaticEnum<T>();
		if (!EnumPtr)
		{
			return FString();
		}

		return EnumPtr->GetNameStringByValue((int64)EnumValue);
	}

	static inline FString BoolToString(bool bValue)
	{
		return bValue ? TEXT("true") : TEXT("false");
	}

	static inline bool IncrementNumericLastPartInString(const FString& SourceString, FString& OutString, const FString& Delimiter)
	{
		TArray<FString> SeparatedStrings;
		const int32 ArraySize = SourceString.ParseIntoArray(SeparatedStrings, *Delimiter);
		if (ArraySize > 0)
		{
			FString& LastPart = SeparatedStrings.Last();
			if (LastPart.IsNumeric())
			{
				LastPart = FString::Printf(TEXT("%d"), FCString::Atoi(*LastPart) + 1);
				OutString = FString::Join(SeparatedStrings, *Delimiter);

				return true;
			}
		}
		return false;
	}

	static inline FString GetNameWithoutPostfix(const FString& SourceString)
	{
		FString ResultString = SourceString;
		int32 PostFixPosition = ResultString.Find(TEXT("_C_"));

		if (PostFixPosition > 0)
		{
			ResultString = ResultString.Left(PostFixPosition);
		}

		return ResultString;
	}

	static inline FString GetAssetNameWithoutPostfix(const FString& SourceString)
	{
		FString ResultString = SourceString;
		int32 PostFixPosition = ResultString.Find(TEXT("_C_"));

		if (PostFixPosition > 0)
		{
			ResultString = ResultString.Left(PostFixPosition + 2);
		}

		return ResultString;
	}
};
