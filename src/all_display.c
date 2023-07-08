/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** to display
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void flag_int(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void flag_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void flag_str(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void flag_u(va_list ap)
{
    my_put_nbr(va_arg(ap,  unsigned int));
}
