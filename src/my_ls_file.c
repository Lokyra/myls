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

int default_folder(char **argv, int i)
{
    DIR *dirp;
    struct dirent *dp;
    struct stat buf;


    dirp = opendir(argv[i]);
    if (dirp == NULL) {
        perror("");
        return 84;
    }

    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_name[0] != '.') {
            stat(dp->d_name, &buf);
            my_printf("%s", dp->d_name);
            my_printf(" ");
        }
    }
    (void)closedir(dirp);
    return 0;
}

int default_ls_file(char **argv, int i)
{
    DIR *dirp;
    struct dirent *dp;
    int n;
    dirp = opendir(".");
    if (dirp == NULL) {
        perror("");
        return 84;
    }
    while ((dp = readdir(dirp)) != NULL) {
        if ((n = my_strcmp(dp->d_name, argv[i]) == 1))
            continue;
        else {
            my_printf("%s", dp->d_name);
            my_printf(" ");
        }
        break;
    }
    (void)closedir(dirp);
    return 0;
}

int default_file(char **argv, int i)
{
    DIR *dirp;
    struct dirent *dp;
    struct stat buf;
    int n;
    dirp = opendir(".");
    if (dirp == NULL) {
        perror("");
        return 84;
    }
    while ((dp = readdir(dirp)) != NULL) {
        if ((n = my_strcmp(dp->d_name, argv[i]) == 0)){
            stat(dp->d_name, &buf);
            print_parameters(dp, buf);
        }
    }
    (void)closedir(dirp);
    return 0;
}
