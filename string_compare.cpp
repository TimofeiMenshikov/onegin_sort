#include <stdio.h>
#include "string_compare.h"


bool is_letter(char symbol)
{
	if (symbol >= 'a' and symbol <= 'z')
	{
		return true;
	}

	if (symbol >= 'A' and symbol <= 'Z')
	{
		return true;
	}

	if (symbol == '\0')
	{
		return true; //  будем считать нуль-терминатор буквой для завершения строки
	}

	return false;
}

enum comp_two_str compare_two_strings(const char* const str1, const char* const str2)
{

	size_t char_number1 = 0;

	size_t char_number2 = 0;

	while (true)
	{
		for(; !is_letter(str1[char_number1]); char_number1++);
		for(; !is_letter(str2[char_number2]); char_number2++);

		if (str1[char_number1] == '\0' && str2[char_number2] == '\0')
		{
			return FIRST_IS_LEFT;
		}

		if (str1[char_number1] < str2[char_number2])
		{
			return FIRST_IS_LEFT;
		}

		if (str1[char_number1] > str2[char_number2])
		{
			return FIRST_IS_RIGHT;
		}

		char_number1++;
		char_number2++;			
	}

}

