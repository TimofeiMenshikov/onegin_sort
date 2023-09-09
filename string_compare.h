#ifndef STRING_COMPARE_H
#define STRING_COMPARE_H

enum comp_two_str
{
	FIRST_IS_LEFT = 1,
	FIRST_IS_RIGHT = -1
};

bool is_letter(char symbol);
enum comp_two_str compare_two_strings(const char* const str1, const char* const str2);
enum comp_two_str compare_two_strings_reversed(const char* const str1, const char* const str2, const size_t strlen1, const size_t strlen2);

#endif /* STRING_COMPARE_H */