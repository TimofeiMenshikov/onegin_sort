#include <stdio.h>
#include "include/string_compare.h"
#include "include/printf_debug.h"

static ssize_t offset_str_to_letter(const char* const str, ssize_t char_number);

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


static ssize_t offset_str_to_letter(const char* const str, ssize_t char_number)
{
	for(; !is_letter(str[char_number]); char_number++);	
	return char_number;
}


enum comp_two_str compare_two_strings(const char* const str1, const char* const str2, const ssize_t strlen1, const ssize_t strlen2)
{
	ssize_t char_number1 = 0;

	ssize_t char_number2 = 0;

	while (true)
	{

		char_number1 = offset_str_to_letter(str1, char_number1);
		char_number2 = offset_str_to_letter(str2, char_number2);

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


	STRCMP_DUMP(printf("string 1: <%s>\n", str1));
	STRCMP_DUMP(printf("string 2: <%s>\n", str2));
	STRCMP_DUMP(printf("strlen1 is %zd\n", strlen1));
	STRCMP_DUMP(printf("strlen2 is %zd\n", strlen2));

	bool return1 = false;
	bool return2 = false;

	while (true)
	{
		STRCMP_DUMP(printf("char_number1 is %zd, symbol is %c(%d)\n", char_number1, str1[char_number1], str2[char_number2]));
		STRCMP_DUMP(printf("char_number2 is %zd, symbol is %c(%d)\n", char_number2, str2[char_number2], str2[char_number2]));

		if ((char_number1 < 0) && (char_number2 < 0))
		{
			STRCMP_DUMP(printf("IS EQUAL, because there is no more letters in str1 and str2\n"));
			return IS_EQUAL;
		}


		if (char_number1 < 0)
		{
			STRCMP_DUMP( printf("FIRST_IS_LEFT, because there is no more letters in str1\n"));
			return FIRST_IS_LEFT;
		}
		if (char_number2 < 0)
		{
			STRCMP_DUMP( printf("FIRST_IS_RIGHT, because there is no more letters in str2\n"));

			return FIRST_IS_RIGHT;
		}

		while (!is_letter(str1[char_number1]))
		{
			char_number1--;
			if (char_number1 < 0)
			{

				return1 = true;
				break;
			}
		}

		//printf("while 1 passed\n");

		while (!is_letter(str2[char_number2]))
		{
			char_number2--;
			if (char_number2 < 0)
			{

				return2 = true;
				break;
			}
		}


		if ((return1 == true) && (return2 == true))
		{
			STRCMP_DUMP(printf("IS EQUAL, because there is no more letters in str1 and str2\n"));
			return IS_EQUAL;

		}

		if (return1 == true)
		{
			STRCMP_DUMP(printf("FIRST_IS_LEFT, because there is no more letters in str1\n"));
			return FIRST_IS_LEFT;
		}
		if (return2 == true)
		{
			STRCMP_DUMP(printf("FIRST_IS_RIGHT, because there is no more letters in str2\n"));
			return FIRST_IS_RIGHT;
		}

		// STRCMP_DUMP(printf("while 2 passed\n"));


		STRCMP_DUMP( printf("char_number1 is %zd char_number2 is %zd\n", char_number1, char_number2));

		if (str1[char_number1] < str2[char_number2])
		{
			STRCMP_DUMP(printf("str[%zd] = %c(%d), str[%zd] = %c(%d), so FIRST_IS_LEFT\n", char_number1, str1[char_number1], str1[char_number1], char_number2, str2[char_number2], str2[char_number2]));
			return FIRST_IS_LEFT;
		}

		if (str1[char_number1] > str2[char_number2])
		{
			STRCMP_DUMP(printf("str[%zd] = %c(%d), str[%zd] = %c(%d), so FIRST_IS_RIGHT\n", char_number1, str1[char_number1], str1[char_number1], char_number2, str2[char_number2], str2[char_number2]));
			return FIRST_IS_RIGHT;
		}

		char_number1--;
		char_number2--;
	}
}


enum comp_two_str compare_two_ptrs(const char* ptr1, const char* ptr2, const ssize_t strlen1, const ssize_t strlen2)
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


