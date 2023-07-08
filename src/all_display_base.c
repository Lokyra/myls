/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** recode
*/
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include <unistd.h>

void flag_b(va_list ap)
{
    my_put_nbr_base(va_arg(ap, unsigned int), "01");
}

void flag_o(va_list ap)
{
    my_put_nbr_base(va_arg(ap, unsigned int), "01234567");
}

void flag_xmin(va_list ap)
{
    my_put_nbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
}

void flag_xmaj(va_list ap)
{
    my_put_nbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
}

void flag_f(va_list ap)
{
    my_put_double(va_arg(ap, double));
}
