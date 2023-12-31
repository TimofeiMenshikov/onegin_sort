#ifndef PRINT_H
#define PRINT_H

void print_text(const char* const * const text, const size_t n_strings, FILE* outputfile);
void print_and_sort(char** const text, const size_t n_strings, ssize_t* string_lengths);
void print_string_lenghts(const ssize_t* const string_lengths, const size_t n_strings);

void print_reversed_str(const char* const str, const size_t str_length);

void print_state( char** arr, const ssize_t size, const ssize_t left, const ssize_t right);

void print_one_sort(char** const text,  const size_t n_strings, ssize_t* const string_lengths, const char* const filename,  enum comp_two_str (*comparator)(const char* const str1, const char* const str2, const ssize_t strlen1, const ssize_t strlen2));
void print_buffer(char* const buffer, const size_t buffer_size);

#endif /* PRINT_H */