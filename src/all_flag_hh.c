/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** code
*/

#include "my.h"
#include <unistd.h>
#include <stdarg.h>

void flag_hho(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "01234567");
}

void flag_hhu(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void flag_hhxmin(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "0123450123456789abcdef");
}

void flag_hhxmaj(va_list ap)
{
    my_put_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
}

void flag_hhi(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}
