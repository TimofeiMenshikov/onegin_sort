#ifndef STRING_FUNCTION_H
#define STRING_FUNCTION_H


enum comp_two_str
{
	FIRST_IS_LEFT = 1,
	FIRST_IS_RIGHT = -1
};


void string_research(const char* const string);
size_t find_n_strings(char* buffer, size_t buffer_size);  // find count of string and replace '\n' to '\0'
size_t find_real_buf_size(char* buffer, size_t buffer_size); // отбрасывает все \0 справа, кроме одного если \0 нет, то ставит \0 как дополнительный символ
void link_text_and_buf(char** text, char* buffer, size_t buffer_size);
void free_all(char** text, char* buffer, size_t n_strings);
void swap_strings(char** pos_1_ptr, char** pos_2_ptr);
void print_text(char** text, size_t n_strings);

#endif /* STRING_FUNCTION_H */