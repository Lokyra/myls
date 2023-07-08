/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** code
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void flag_llo(va_list ap)
{
    my_put_nbr_ll_base(va_arg(ap, long long int), "01234567");
}

void flag_llu(va_list ap)
{
    my_put_longlong_nbr(va_arg(ap, unsigned long long int));
}

void flag_llxmin(va_list ap)
{
    my_put_nbr_ll_base(va_arg(ap, long long int), "0123450123456789abcdef");
}

void flag_llxmaj(va_list ap)
{
    my_put_nbr_ll_base(va_arg(ap, long long int), "0123456789ABCDEF");
}

void flag_lli(va_list ap)
{
    my_put_longlong_nbr(va_arg(ap, unsigned long long int));
}
