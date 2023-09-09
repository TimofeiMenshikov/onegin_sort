#include <stdio.h>

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


static enum comp_two_str compare_two_strings_reversed(const char* const str1, const char* const str2, const size_t strlen1, const size_t strlen2)
{
	size_t char_number1 = strlen1 - 1;
	size_t char_number2 = strlen2 - 1;

}


int main()
{
	print_reversed_str("12345", 5);
}