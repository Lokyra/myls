/*
** EPITECH PROJECT, 2022
** function
** File description:
** hastag
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>

void flag_hashtag_min(va_list ap)
{
    write(1, "0x", 2);
    my_put_nbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
}

void flag_hashtag_maj(va_list ap)
{
    write(1, "0X", 2);
    my_put_nbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
}

void flag_hashtag_o(va_list ap)
{
    write(1, "0", 1);
    my_put_nbr_base(va_arg(ap, unsigned int), "01234567");
}
