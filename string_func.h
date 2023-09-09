#ifndef STRING_FUNCTION_H
#define STRING_FUNCTION_H


enum comp_two_str
{
	FIRST_IS_LEFT = 1,
	FIRST_IS_RIGHT = -1
};


void string_research(const char* const string);
size_t find_real_buf_size(char*  buffer, size_t buffer_size); // отбрасывает все \0 справа, кроме одного если \0 нет, то ставит \0 как дополнительный символ
void link_text_and_buf(char** const text,  char* const buffer, const size_t buffer_size);
void free_all(char** text, char* buffer, size_t* string_lengths);
void swap_strings(char** const pos_1_ptr, char** const pos_2_ptr);
void print_text(const char* const * const text, const size_t n_strings);
void print_and_sort(char** const text, const size_t n_strings);
size_t* find_str_lens(const char* const * const text, size_t n_strings);


enum comp_two_str compare_two_strings(const char* const str1, const char* const str2);
void sort_strings(char** const text, size_t n_strings);

#endif /* STRING_FUNCTION_H */