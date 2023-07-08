/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** print_block
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

int get_total_block(struct stat buf, char **argv)
{
    DIR *dirp;
    struct dirent *dp;
    int total_block = 0;
    dirp = opendir(".");
    if (dirp == NULL)
        return 84;
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_name[0] == '.'){
            continue;
        } else {
            stat(dp->d_name, &buf);
            total_block = total_block + (buf.st_blocks / 2);
        }
    }
    return total_block;
}

void display_block(int total_block, int flag_l)
{
    if (flag_l == 1) {
        my_printf("total %d", total_block);
        my_printf("\n");
    }
}

int default_ls(void)
{

    DIR *dirp;
    struct dirent *dp;


    dirp = opendir(".");
    if (dirp == NULL) {
        perror("");
        return 84;
    }
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_name[0] != '.') {
            my_printf("%s", dp->d_name);
            my_printf(" ");
        }

    }
    (void)closedir(dirp);

    return 0;
}

void my_put_date(char *str)
{
    for (int i = 4; i < 16; i++) {
        my_printf("%c",str[i]);
    }
    my_printf(" ");
}

void print_id(struct stat buf)
{

    struct passwd *name_id;
    struct group *group_id;

    name_id = getpwuid(buf.st_uid);
    group_id = getgrgid(buf.st_gid);

    my_printf(" ");
    my_printf("%s", group_id->gr_name);
    my_printf(" ");
    my_printf("%s", name_id->pw_name);
    my_printf(" ");
}
/*
int default_ls_file(char **argv)
{
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(argv[1]);
    if (dirp == NULL) {
        perror("");
        return 84;
    }
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_name[0] == '.')
            continue;
        else {
            my_printf("%s", dp->d_name);
            my_printf(" ");
        }
    }
    (void)closedir(dirp);
    return 0;
}
*/
