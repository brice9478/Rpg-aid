/*
** EPITECH PROJECT, 2023
** my
** File description:
** contains all prototypes
*/

#include <stdarg.h>

#ifndef MY_FUNCTIONS_H
    #define MY_FUNCTIONS_H

void my_putchar(char c);
int my_isneg(int nb);
void my_putnbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_print_comb(void);
int extra_for_my_print_comb(int i, int j, int k);
char *concat_params(int argc, char **argv);
int my_print_alpha(void);
int my_print_digits(void);
int my_print_revalpha(void);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str);
void print_char(va_list args);
void print_string(va_list args);
void print_number(va_list args);
void print_hex(va_list args);
void print_hex_caps(va_list args);
void my_puthex(unsigned int decimal);
void my_puthex_caps(unsigned int decimal);
void my_putfloat(double nb, int precision);
void print_float(va_list args);
int print_float_comma(va_list args, const char *format, int i);
void print_octal(va_list args);
void print_pointer(va_list args);
void my_putpoint(const void *ptr);
void my_printf(const char *format, ...);
void print_undecimal(va_list args);
int hashtag_hex(va_list args, int i);
int hashtag_hex_caps(va_list args, int i);
int hashtag_float(va_list args, int i);
int hashtag_octal(va_list args, int i);
int hashtag_e(va_list args, int i);
int hashtag_e_cap(va_list args, int i);
void print_e(va_list args);
void print_science_cap(va_list args);
int print_science_cap_comma(va_list args, const char *format, int i);
int print_e_comma(va_list args, const char *format, int i);
void print_g_flag(va_list args);
double special_putfloat(double nb, const char *format, int i);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
double negative(double nb);
void end(int power);
char *science_to_str(double nb);
char *end_str(int power, char *str, char **format);
char *negative_str(double nb, double absolute_nb);
int number_flag(va_list args, char const *format, int i);
void my_itoa(int num, char *str);
int minus_flag(va_list args, char const *format, int i);
int plus_flag(va_list args, char const *format, int i);
int flags_l(char const *format, int i, va_list args);
void l_print_number(va_list args);
void l_print_hex(va_list args);
void l_print_hex_caps(va_list args);
void l_my_puthex(unsigned long int decimal);
void l_my_puthex_caps(unsigned long int decimal);
void ll_print_number(va_list args);
void ll_print_hex(va_list args);
void ll_print_hex_caps(va_list args);
void ll_my_puthex(unsigned long long int decimal);
void ll_my_puthex_caps(unsigned long long int decimal);
void l_print_octal(va_list args);
void ll_print_octal(va_list args);
void l_print_undecimal(va_list args);
void ll_print_undecimal(va_list args);
void l_my_putnbr(long int nb);
void ll_my_putnbr(long long int nb);
void rounding(double decimal, int precision);
void itoa_loop(int i, char *str);
int determine_nb(int j, int i, char const *format);

#endif // MY_FUNCTIONS_H
