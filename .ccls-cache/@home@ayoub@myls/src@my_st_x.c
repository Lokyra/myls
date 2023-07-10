/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** code
*/

#include "my.h"

static int check_char(char a, char b)
{
    if (a == b)
        return 0;
    else
        return (a - b);
}

int my_st_x(char const *s1, char const *s2, int n, int j)
{
    int value = 0;
    int i = 0;

    if (!s1 || !s2)
        return -1;
    for (; s1[i] && s2[j] && i < n; ++i, ++j) {
        value = check_char(s1[i], s2[j]);
        if (value == 0) {
            continue;
        } else {
            return value;
        }
    }
    return 0;
}
