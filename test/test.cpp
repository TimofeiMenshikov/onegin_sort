#include <stdio.h>
#include <stdlib.h>
enum comp_two_str
{
	FIRST_IS_LEFT = 1,
	IS_EQUAL = 0,
	FIRST_IS_RIGHT = -1,
	INVALID_NUMBER = 2
};
#include "../include/printf_debug.h"


static void print_reversed_str(const char* const str, const size_t str_length)
{
	for (ssize_t char_number = str_length - 1; char_number >= 0; char_number--)
	{
		putchar(str[char_number]);
	}
}


static bool is_letter(char symbol)
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


static enum comp_two_str compare_two_strings(const char* const str1, const char* const str2)
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

// создать буфер размером максимальной строки, фильтровать туда строки убирая пробелы и другие символы

// задача о получении максимальной длины строки

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


/*static void my_qsort(char **arr, ssize_t first, ssize_t last)
{
    if (first < last)
    {
        ssize_t left = first;
        ssize_t right = last;
        char* middle = arr[(first + last) / 2];

        do
        {
            while (compare_two_strings(arr[left], middle) == FIRST_IS_LEFT)
            {
            	//print_state(arr, last + 1, left, right, middle);
            	left++;		
            } 

            while (compare_two_strings(arr[right] > middle) == FIRST_IS_RIGHT)
            {
            	//print_state(arr, last + 1, left, right, middle);
            	right--;
            }
            
            if (left <= right)
            {
            	swap_strings(arr + right, arr + left);

                left++;
                right--;
            }

        } while (left <= right);

        my_qsort(arr, first, right);
        my_qsort(arr, left, last);
    }
}*/


int main()
{
	char str1[] = "\n";
	char str2[] = "\n";

	printf("%s", str1);

	enum comp_two_str compare = compare_two_strings_reversed(str1, str2, 1, 1);
	
	/*if (compare == FIRST_IS_RIGHT)
	{
		printf("FIRST_IS_RIGHT");
	}
	else if (compare == FIRST_IS_LEFT)
	{
		printf("FIRST_IS_LEFT");
	}
	else
	{
		printf("no value");
	}
	*/
}