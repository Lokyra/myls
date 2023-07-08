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

char *my_strcpy(char *dest, char *src)
{
    int len = my_strlen(src);
    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}

char *my_strcat(char *dest, char *src)
{
    int len = my_strlen(dest);

    for (int j = 0; src[j] != '\0'; ++j, ++len) {
        dest[len] = src[j];
    }

    dest[len] = '\0';

    return dest;
}

void get_folder_element(char *str, char *arr,struct dirent *dp,struct stat buf)
{
    char *filepath = malloc(sizeof(char) * 10000);
    my_strcpy(arr, dp->d_name);
    filepath = my_strcat(str, arr);
    stat(filepath, &buf);
    print_parameters(dp, buf);

}

void reset_str(char *str, char **argv, int i, int len)
{
    str[0] = '\0';
    my_strcpy(str, argv[i]);
    str[len] = '/';
    str[len + 1] = '\0';
}

int default_ls_folder(char **argv, int i, int flag_l)
{
    DIR *dirp;
    struct dirent *dp;
    struct stat buf;
    char str[256];
    char arr[256];
    int err = stat(argv[i], &buf);
    dirp = opendir(argv[i]);
    if (dirp == NULL)
        return 84;
    my_strcpy(str, argv[i]);
    int len = my_strlen(str);
    str[len] = '/';
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_name[0] != '.') {
            get_folder_element(str, arr, dp, buf);
            reset_str(str, argv, i, len);
        }
    }
    (void)closedir(dirp);
}
