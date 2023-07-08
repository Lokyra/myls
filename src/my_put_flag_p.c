/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** pointeur
*/

#include "my.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int my_put_flag_p(unsigned long long int nb, char *str)
{
    unsigned long long int div = 1;
    unsigned long long int base = my_strlen(str);

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

void flag_p(va_list ap)
{
    write(1, "0x", 2);
    my_put_flag_p(va_arg(ap, unsigned long long int), "0123456789abcdef");

}
