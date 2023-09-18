#ifndef STRING_FUNCTION_H
#define STRING_FUNCTION_H

void string_research(const char* const string);
size_t find_real_buf_size(char*  buffer, size_t buffer_size); // отбрасывает все \0 справа, кроме одного если \0 нет, то ставит \0 как дополнительный символ
void link_text_and_buf(char** const text,  char* const buffer, const size_t buffer_size);
void free_all(char** text, char* buffer, ssize_t* string_lengths);
size_t find_n_strings(char* const buffer, const size_t buffer_size);  // find count of string and replace '\n' to '\0'

ssize_t* find_str_lens(const char* const * const text, size_t n_strings);

#endif /* STRING_FUNCTION_H */