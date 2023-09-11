#include <stdio.h>
#include <stdlib.h>

enum comp_two_str
{
	FIRST_IS_LEFT = 1,
	FIRST_IS_RIGHT = -1
};


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

static enum comp_two_str compare_two_strings_reversed(const char* const str1, const char* const str2, const size_t strlen1, const size_t strlen2)
{
	ssize_t char_number1 = strlen1 - 1;
	ssize_t char_number2 = strlen2 - 1;

	while (true)
	{
		printf("char_number1 is %zu\n", char_number1);
		printf("char_number2 is %zu\n", char_number2);

		if (char_number1 < 0)
		{
			printf("FIRST_IS_RIGHT, because there is no more letters in str1");
			return FIRST_IS_RIGHT;
		}
		if (char_number2 < 0)
		{
			printf("FIRST_IS_LEFT, because there is no more letters in str2");
			return FIRST_IS_LEFT;
		}

		while (!is_letter(str1[char_number1]))
		{
			char_number1--;
			if (char_number1 < 0)
			{
				printf("FIRST_IS_RIGHT, because there is no more letters in str1");
				return FIRST_IS_RIGHT;
			}
		}

		while (!is_letter(str2[char_number2]))
		{
			char_number2--;
			if (char_number2 < 0)
			{
				printf("FIRST_IS_LEFT, because there is no more letters in str2");
				return FIRST_IS_LEFT;
			}
		}

		printf("char_number1 is %zu char_number2 is %zu\n", char_number1, char_number2);

		if (str1[char_number1] < str2[char_number2])
		{
			printf("str[%zu] = %c(%d), str[%zu] = %c(%d), so FIRST_IS_LEFT", char_number1, str1[char_number1], str1[char_number1], char_number2, str2[char_number2], str2[char_number2]);
			return FIRST_IS_LEFT;
		}

		if (str1[char_number1] > str2[char_number2])
		{
			printf("str[%zu] = %c(%d), str[%zu] = %c(%d), so FIRST_IS_RIGHT", char_number1, str1[char_number1], str1[char_number1], char_number2, str2[char_number2], str2[char_number2]);
			return FIRST_IS_RIGHT;
		}

		char_number1--;
		char_number2--;
	}
}


int main()
{
	char* str = (char*) calloc(10, sizeof(char));

	for (size_t i = 0; i < 10; i++)
	{
		str[i] = i + 90;
	}

	str++;
	str++;

	printf("%s", str);

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