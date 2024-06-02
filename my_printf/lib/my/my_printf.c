/*
** EPITECH PROJECT, 2023
** disp_stdarg
** File description:
** things
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static void (*pfunc[14])(va_list) = {
    &print_char,
    &print_string,
    &print_number,
    &print_number,
    &print_hex,
    &print_hex_caps,
    &print_float,
    &print_float,
    &print_octal,
    &print_undecimal,
    &print_pointer,
    &print_e,
    &print_science_cap,
    &print_g_flag
};

static int (*psub[7])(va_list, int) = {
    &hashtag_hex,
    &hashtag_hex_caps,
    &hashtag_float,
    &hashtag_float,
    &hashtag_octal,
    &hashtag_e,
    &hashtag_e_cap
};

static int (*pcomma[4])(va_list, const char *, int) = {
    &print_float_comma,
    &print_float_comma,
    &print_e_comma,
    &print_science_cap_comma
};

static int (*pwidth[2])(va_list, const char *, int) = {
    &plus_flag,
    &minus_flag
};

int sub_hashtag(const char *format, va_list args, const char *tab, int i)
{
    int tabindex;

    for (tabindex = 0; tabindex < 7; tabindex++) {
        if (format[i + 1] == '#' && format[i + 2] == tab[tabindex]) {
            i = psub[tabindex](args, i);
            return i;
        }
    }
    return i;
}

int sub_params(const char *format, int i, va_list args, int a)
{
    char tab[7] = {'x', 'X', 'f', 'F', 'o', 'e', 'E'};
    char tabcomma[4] = {'f', 'F', 'e', 'E'};
    char tabsub[2] = {'+', '-'};
    char *str;

    for (int tabindex = 0; tabindex < 4 && format[i + 1] == '.'; tabindex++) {
        if (format[a] == tabcomma[tabindex])
            return pcomma[tabindex](args, format, i) - 1;
        if (tabindex + 1 == 4) {
            tabindex = -1;
            a++;
        }
    }
    for (int tabindex = 0; tabindex < 2; tabindex++) {
        if (format[i + 1] == tabsub[tabindex])
            return pwidth[tabindex](args, format, i);
    }
    if (format[i + 1] >= '0' && format[i + 1] <= '9')
        return number_flag(args, format, i);
    return sub_hashtag(format, args, tab, i);
}

int check_tab(const char *format, int i, va_list args)
{
    char tab[14] = {'c', 's', 'i', 'd', 'x', 'X', 'f', 'F', 'o', 'u', 'p', 'e',
        'E', 'g'};
    int tabindex;
    int check = 0;

    for (tabindex = 0; tabindex < 14; tabindex++) {
        if (format[i] == '%' && format[i + 1] == tab[tabindex]) {
            pfunc[tabindex](args);
            return i + 1;
        }
    }
    for (tabindex = 0; tabindex < 14; tabindex++) {
        if (format[i] == '%' && format[i + 1] != tab[tabindex]) {
            i = sub_params(format, i, args, i + 1);
            return i;
        }
    }
    if (format[i] == '%' && format[i + 1] == '%') {
        my_putchar('%');
    }
}

void my_printf(const char *format, ...)
{
    va_list args;
    int i;

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i = check_tab(format, i, args);
            i = flags_l(format, i, args);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(args);
}
