/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** code
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void flag_lo(va_list ap)
{
    my_put_nbr_long_base(va_arg(ap, long int), "01234567");
}

void flag_lu(va_list ap)
{
    my_put_long_nbr(va_arg(ap, unsigned long int));
}

void flag_lxmin(va_list ap)
{
    my_put_nbr_long_base(va_arg(ap, long int), "0123450123456789abcdef");
}

void flag_lxmaj(va_list ap)
{
    my_put_nbr_long_base(va_arg(ap, long int), "0123456789ABCDEF");
}

void flag_li(va_list ap)
{
    my_put_long_nbr(va_arg(ap, long int));
}
