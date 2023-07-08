/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** maj s
*/

#include "my.h"
#include <unistd.h>

static void display_low(int nb)
{
    if (nb < 10)
        my_putchar('0');
}

void my_put_maj_s(char *str)
{
    for (int i = 0; str[i]; ++i) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_putchar('0');
            display_low(str[i]);
            my_put_nbr_base(str[i], "01234567");
        } else {
            my_putchar(str[i]);
        }
    }
}
