/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** fonction
*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static const mini_t arr[] = {
    {"i", &flag_int},
    {"d", &flag_int},
    {"c", &flag_char},
    {"s", &flag_str},
    {"b", &flag_b},
    {"o", &flag_o},
    {"u", &flag_u},
    {"x", &flag_xmin},
    {"X", &flag_xmaj},
    {"p", &flag_p},
    {"f", &flag_f},
    {"F", &flag_f},
    {"lo", &flag_lo},
    {"lu", &flag_lu},
    {"lx", &flag_lxmin},
    {"lX", &flag_lxmaj},
    {"ld", &flag_li},
    {"li", &flag_li},
    {"llo", &flag_llo},
    {"llu", &flag_llu},
    {"llx", &flag_llxmin},
    {"llX", &flag_llxmaj},
    {"lld", &flag_lli},
    {"lli", &flag_lli},
    {"qo", &flag_llo},
    {"qu", &flag_llu},
    {"qx", &flag_llxmin},
    {"qX", &flag_llxmaj},
    {"qd", &flag_lli},
    {"qi", &flag_lli},
    {"zo", &flag_zo},
    {"zu", &flag_zu},
    {"zx", &flag_zxmin},
    {"zX", &flag_zxmaj},
    {"zd", &flag_zi},
    {"zi", &flag_zi},
    {"ho", &flag_ho},
    {"hu", &flag_hu},
    {"hx", &flag_hxmin},
    {"hX", &flag_hxmaj},
    {"hd", &flag_hi},
    {"hi", &flag_hi},
    {"hho", &flag_hho},
    {"hhu", &flag_hhu},
    {"hhx", &flag_hhxmin},
    {"hhX", &flag_hhxmaj},
    {"hhd", &flag_hhi},
    {"hhi", &flag_hhi}
};

static const mini_t tab[] = {
    {"o", &flag_hashtag_o},
    {"x", &flag_hashtag_min},
    {"X", &flag_hashtag_maj},
    {"f", &flag_f},
    {"F", &flag_f}
};

static void add_x(int i, int *x)
{
    if (my_strlen(arr[i].str) > 1)
        *x += my_strlen(arr[i].str) - 1;
}

static void check_simple_flag(char const *flag, int *x, va_list chaines)
{
    for (int i = 0; i < 49; ++i) {
        if (my_st_x(arr[i].str, flag, my_strlen(arr[i].str), *x + 1) == 0) {
            arr[i].f(chaines);
            add_x(i, x);
            return;
        }
    }
}

static void check_hashtag_flag(char const *flag, int *x, va_list chaines)
{
    for (int i = 0; i < 5; ++i) {
        if (my_st_x(tab[i].str, flag, my_strlen(tab[i].str), *x + 2) == 0) {
            tab[i].f(chaines);
            return;
        }
    }
}

static void find_char(char const *str, int *x, va_list chaines)
{
    if (check_error(str[*x + 1]) == 84)
        return;
    if (str[*x + 2] && str[*x + 1] == '#') {
        check_hashtag_flag(str, x , chaines);
        (*x)++;
        return;
    }
    check_simple_flag(str, x, chaines);
}

int my_printf(const char *format, ...)
{
    va_list chaines;
    int count = 0;
    int true = 1;

    if (format == NULL)
        return 0;
    va_start(chaines, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] != '%' && true == 1) {
            my_putchar(format[i]);
            count++;

        } else {
            find_char(format, &i, chaines);
            true = 0;
            ++i;
        }
    }
    va_end(chaines);
    return 0;
}
