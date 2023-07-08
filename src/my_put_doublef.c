/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** fonction pour le f
*/
#include "my.h"
#include <unistd.h>

int my_put_double(double a)
{
    int count = 0;

    if (a == 0) {
        write(1, "0.000000", 8);
        return 0;
    }
    if (a < 10)
        count = 1;

    my_put_nbr(a);
    a -= (int) a;
    a = a * 1000000;
    write(1, ".", 1);

    if (a == 0.0) {
        write(1, "0000000", 6);
        return 0;
    }
    my_put_nbr(a);
    return 0;
}
