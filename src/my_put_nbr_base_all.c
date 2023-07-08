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

int my_put_nbr_long_base(long int nb, char *str)
{
    int div = 1;
    int base = my_strlen(str);

    if (nb < 0)
        return -1;
    if (nb == 0) {
        write(1, "0", 1);
        return 0;
    }
    if (str == NULL)
        return 84;
    while ((nb / div) >= base) {
        div *= base;
    }
    for (int res = 0; div > 0; div /= base) {
        res = ((nb / div) % base);
        write(1, &str[res], 1);
    }
    return 0;
}

int my_put_nbr_ll_base(long long int nb, char *str)
{
    int div = 1;
    int base = my_strlen(str);

    if (nb < 0)
        return -1;
    if (nb == 0) {
        write(1, "0", 1);
        return 0;
    }
    if (str == NULL)
        return 84;
    while ((nb / div) >= base) {
        div *= base;
    }
    for (int res = 0; div > 0; div /= base) {
        res = ((nb / div) % base);
        write(1, &str[res], 1);
    }
    return 0;
}

int my_put_nbr_z_base(size_t nb, char *str)
{
    int div = 1;
    int base = my_strlen(str);

    if (nb < 0)
        return -1;
    if (nb == 0) {
        write(1, "0", 1);
        return 0;
    }
    if (str == NULL)
        return 84;
    while ((nb / div) >= base) {
        div *= base;
    }
    for (int res = 0; div > 0; div /= base) {
        res = ((nb / div) % base);
        write(1, &str[res], 1);
    }
    return 0;
}
