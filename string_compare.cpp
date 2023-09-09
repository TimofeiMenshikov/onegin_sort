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

	return false;
}

enum comp_two_str compare_two_strings(const char* const str1, const char* const str2)
{
	for (size_t char_number = 0;;char_number++)
	{
		if (str1[char_number] == '\0' && str2[char_number] == '\0')
		{
			return FIRST_IS_LEFT;
		}

		if (str1[char_number] < str2[char_number])
		{
			return FIRST_IS_LEFT;
		}

		if (str1[char_number] > str2[char_number])
		{
			return FIRST_IS_RIGHT;
		}
	}

	return FIRST_IS_LEFT;
}
