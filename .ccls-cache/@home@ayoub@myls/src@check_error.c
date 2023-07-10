/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** code
*/

#include "my.h"

int check_error(char flag)
{
    if (flag == 0)
        return 84;
    if (flag == '%') {
        my_putchar('%');
        return 84;
    }

    return 0;
}
