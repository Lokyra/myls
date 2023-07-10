/*
** EPITECH PROJECT, 2022
** compilateur
** File description:
** fonction
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int my_put_nbr(int a)
{
    if (a >= -2147483647) {
        if (a < 0) {
            a = a * (-1);
            my_putchar('-');
        }
        if (a >= 10)
            my_put_nbr(a / 10);
        a = a % 10;
        a = a + 48;
        my_putchar(a);
    } else {
        write(1, "-2147483648", 11);
    }
    return 0;
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

int my_put_nbr_base(int nb, char *str)
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
