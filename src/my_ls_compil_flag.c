/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** display flags
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"

int display_flag_a(struct dirent *dp, struct stat buf, int flag_a, int flag_l)
{
    if (flag_a == 1 && flag_l == 0){
        stat(dp->d_name, &buf);
        my_printf("%s", dp->d_name);
        my_printf(" ");
    }
    return 0;
}

int display_flag_l(struct dirent *dp, struct stat buf, int flag_a, int flag_l)
{
    if (flag_l == 1 && flag_a == 0 && dp->d_name[0] != '.') {
        stat(dp->d_name, &buf);
        print_parameters(dp, buf);
    }
    return 0;
}

int check_flag(int flag_a, int flag_l)
{
    if (flag_l != 0 && flag_a != 0)
        return 84;
}

int assign_flag2(char **argv, int argc, int *p_a, int *p_l)
{
    int n;

    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-l") == 0)
            *p_l = 1;

        if (my_strcmp(argv[i], "-a") == 0)
            *p_a = 1;
    }

    return 0;
}

int my_strcmp(char *s1, char *s2)
{
    int firstLen = my_strlen(s1);
    int secondLen = my_strlen(s2);
    int len = firstLen;
    int result = 0;

    if (firstLen != secondLen)
        return 1;

    for (int i = 0; i < len; i++) {
        if (s1[i] == s2[i])
            result++;
    }

    if (result == len)
        return 0;


    return 1;
}
