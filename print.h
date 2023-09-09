#ifndef PRINT_H
#define PRINT_H

void print_text(const char* const * const text, const size_t n_strings);
void print_and_sort(char** const text, const size_t n_strings, size_t* string_lengths);
void print_string_lenghts(const size_t* const string_lengths, const size_t n_strings);

void print_reversed_str(const char* const str, const size_t str_length);

#endif /* PRINT_H */