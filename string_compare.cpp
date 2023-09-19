#include <stdio.h>
#include "include/string_compare.h"


// в функцию сравнения 2 строк нужно добаить вариант, когда строки равны, потому что в qsort элемент, равный разделяющему нужно менять всегда


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


size_t offset_str_to_letter(const char* const str, size_t char_number)
{
	for(; !is_letter(str[char_number]); char_number++);	
	return char_number;
}


enum comp_two_str compare_two_strings(const char* const str1, const char* const str2)
{
	size_t char_number1 = 0;

	size_t char_number2 = 0;

	while (true)
	{

		char_number1 = offset_str_to_letter(str1, char_number1);
		char_number2 = offset_str_to_letter(str2, char_number2);

		for(; !is_letter(str1[char_number1]); char_number1++);
		for(; !is_letter(str2[char_number2]); char_number2++); //todo func

		if (str1[char_number1] == '\0' && str2[char_number2] == '\0')
		{
			return IS_EQUAL;
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


enum comp_two_str compare_two_strings_reversed(const char* const str1, const char* const str2, const ssize_t strlen1, const ssize_t strlen2)
{
	ssize_t char_number1 = strlen1 - 1;
	ssize_t char_number2 = strlen2 - 1;


	//printf("string 1: <%s>\n", str1);
	//printf("string 2: <%s>\n", str2);
	//printf("strlen1 is %zd\n", strlen1);
	//printf("strlen2 is %zd\n", strlen2);

	while (true)
	{
		//printf("char_number1 is %zd\n", char_number1);
		//printf("char_number2 is %zd\n", char_number2);

		if ((char_number1 < 0) && (char_number2 < 0))
		{
			return IS_EQUAL;
		}


		if (char_number1 < 0)
		{
			//printf("FIRST_IS_RIGHT, because there is no more letters in str1\n");
			return FIRST_IS_RIGHT;
		}
		if (char_number2 < 0)
		{
			//printf("FIRST_IS_LEFT, because there is no more letters in str2\n");
			return FIRST_IS_LEFT;
		}

		while (!is_letter(str1[char_number1]))
		{
			char_number1--;
			if (char_number1 < 0)
			{
				//printf("FIRST_IS_RIGHT, because there is no more letters in str1\n");
				return FIRST_IS_RIGHT;
			}
		}

		while (!is_letter(str2[char_number2]))
		{
			char_number2--;
			if (char_number2 < 0)
			{
				//printf("FIRST_IS_LEFT, because there is no more letters in str2");
				return FIRST_IS_LEFT;
			}
		}


		//printf("char_number1 is %zd char_number2 is %zd\n", char_number1, char_number2);

		if (str1[char_number1] < str2[char_number2])
		{
			//printf("str[%zd] = %c(%d), str[%zd] = %c(%d), so FIRST_IS_LEFT", char_number1, str1[char_number1], str1[char_number1], char_number2, str2[char_number2], str2[char_number2]);
			return FIRST_IS_LEFT;
		}

		if (str1[char_number1] > str2[char_number2])
		{
			//printf("str[%zd] = %c(%d), str[%zd] = %c(%d), so FIRST_IS_RIGHT", char_number1, str1[char_number1], str1[char_number1], char_number2, str2[char_number2], str2[char_number2]);
			return FIRST_IS_RIGHT;
		}

		char_number1--;
		char_number2--;
	}
}


enum comp_two_str compare_two_ptrs(const char* ptr1, const char* ptr2)
{
	if (ptr1 == ptr2)
	{
		return IS_EQUAL;
	}

	if (ptr1 > ptr2)
	{
		return FIRST_IS_RIGHT;
	}

	return FIRST_IS_LEFT;
}


