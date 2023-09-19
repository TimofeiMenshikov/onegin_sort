#ifndef STRING_COMPARE_H
#define STRING_COMPARE_H

enum comp_two_str
{
	FIRST_IS_LEFT = 1,
	IS_EQUAL = 0,
	FIRST_IS_RIGHT = -1,
	INVALID_NUMBER = 2
};

bool is_letter(char symbol);
enum comp_two_str compare_two_strings(const char* const str1, const char* const str2, const ssize_t strlen1, const ssize_t strlen2);
enum comp_two_str compare_two_strings_reversed(const char* const str1, const char* const str2, const ssize_t strlen1, const ssize_t strlen2);
enum comp_two_str compare_two_ptrs(const char* ptr1, const char* ptr2, const ssize_t strlen1, const ssize_t strlen2);

#endif /* STRING_COMPARE_H */