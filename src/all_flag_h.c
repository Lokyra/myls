/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** code
*/

#include "my.h"
#include <unistd.h>
#include <stdarg.h>

void flag_ho(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "01234567");
}

void flag_hu(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void flag_hxmin(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "0123450123456789abcdef");
}

void flag_hxmaj(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
}

void flag_hi(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}
