/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** code
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void flag_zo(va_list ap)
{
    my_put_nbr_z_base(va_arg(ap, size_t), "01234567");
}

void flag_zu(va_list ap)
{
    my_put_z(va_arg(ap, size_t));
}

void flag_zxmin(va_list ap)
{
    my_put_nbr_z_base(va_arg(ap, size_t), "0123450123456789abcdef");
}

void flag_zxmaj(va_list ap)
{
    my_put_nbr_z_base(va_arg(ap, size_t), "0123456789ABCDEF");
}

void flag_zi(va_list ap)
{
    my_put_z(va_arg(ap, size_t));
}
