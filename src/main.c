/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** main
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"

/*

    if (argc != 2)
        default_ls();
    else {
        //assign_flag(argv, p_a, p_l);
        default_ls2(flag_a, flag_l);
    }
*/

/*
int assign_flag(char **argv, int *p_a, int *p_l)
{
    int len = my_strlen(argv[1]);

    for (int i = 0; i <= len; i++) {
        if (argv[1][0] == '-' && argv[1][i] == 'l')
            *p_l = 1;

        if (argv[1][0] == '-' && argv[1][i] == 'a')
            *p_a = 1;
    }
    return 0;
}
*/

/*
int default_ls3(int flag_a, int flag_l)
{
    DIR *dirp;
    struct dirent *dp;
    struct stat buf;

    dirp = opendir(".");
    check_dir(dirp);

    while ((dp = readdir(dirp)) != NULL) {
        if (S_ISDIR(buf.st_mode1)) {
            stat(dp->d_name, &buf);
            print_parameters(dp);
        }
        display_flag_a(dp, buf, flag_a, flag_l);
        display_flag_l(dp, buf, flag_a, flag_l);
    }
    (void)closedir(dirp);
    return 0;
}
*/

/*
int default_ls2(int flag_a, int flag_l)
{
    DIR *dirp;
    struct dirent *dp;
    struct stat buf;
    if (flag_l == 0 && flag_a == 0)
        return 84;
    dirp = opendir(".");
    check_dir(dirp);
    int total_block = get_total_block(buf);
    display_block(total_block, flag_l);
    while ((dp = readdir(dirp)) != NULL) {
        if (flag_l == 1 && flag_a == 1) {
            stat(dp->d_name, &buf);
            print_parameters(dp);
        }
        display_flag_a(dp, buf, flag_a, flag_l);
        display_flag_l(dp, buf, flag_a, flag_l);
    }
    (void)closedir(dirp);
    return 0;
}
*/


int check_dir(DIR *dirp)
{
    if (dirp == NULL) {
        perror("");
        return 84;
    }
    return 0;
}

void display_folder(char **argv, int i, int flag_l, int flag_a)
{
    if (flag_l == 1)
        default_ls_folder(argv, i, flag_l);
    else
        default_folder(argv, i);

}

void display_file(char **argv, int i,  int flag_l, int flag_a)
{
    if (flag_l == 1)
        default_file(argv, i);
    else
        default_ls_file(argv, i);
}

void display_ls(char **argv, int argc, int flag_a, int flag_l)
{
    int i = 0;

    for (i = 1; i < argc; i++) {
        struct stat st;
        stat(argv[i], &st);

        if (S_ISDIR(st.st_mode))
            display_folder(argv, i, flag_l, flag_a);
        if (S_ISREG(st.st_mode))
            display_file(argv, i, flag_l, flag_a);
    }

}

int main (int argc, char **argv)
{
    int flag_a = 0;
    int flag_l = 0;
    int *p_a = &flag_a;
    int *p_l = &flag_l;

    if (argc == 1) {
        default_ls();
    } else {
        assign_flag2(argv, argc, p_a, p_l);
        display_ls(argv, argc, flag_a, flag_l);
    }
    return 0;
}
