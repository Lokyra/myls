/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** code
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_put_long_nbr(long int a)
{
    if (a >= -2147483647) {
        if (a < 0) {
            a = a * (-1);
            my_putchar('-');
        }
        if (a >= 10)
            my_put_long_nbr(a / 10);
        a = a % 10;
        a = a + 48;
        my_putchar(a);
    } else {
        write(1, "-2147483648", 11);
    }
    return 0;
}

int my_put_longlong_nbr(long long int a)
{
    if (a >= -9223372036854775807) {
        if (a < 0) {
            a = a * (-1);
            my_putchar('-');
        }
        if (a >= 10)
            my_put_longlong_nbr(a / 10);
        a = a % 10;
        a = a + 48;
        my_putchar(a);
    } else {
        write(1, "-9223372036854775807", 20);
    }
    return 0;
}

int my_put_z(size_t a)
{
    if (a < 0) {
        a = a * (-1);
        my_putchar('-');
    }
    if (a >= 10)
        my_put_z(a / 10);
    a = a % 10;
    a = a + 48;
    my_putchar(a);
    return 0;
}
