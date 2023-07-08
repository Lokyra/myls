/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** parameters
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


void print_usr_rights(struct stat buf)
{
    my_printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
    my_printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
    my_printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
}

void print_grp_rights(struct stat buf)
{
    my_printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
    my_printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
    my_printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
}

void print_oth_rights(struct stat buf)
{
    my_printf( (buf.st_mode & S_IROTH) ? "r" : "-");
    my_printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
    my_printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
}

void print_rights(struct stat buf)
{
    my_printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
    print_usr_rights(buf);
    print_grp_rights(buf);
    print_oth_rights(buf);
    my_printf(" ");
}

int print_parameters(struct dirent *dp, struct stat buf)
{
    int err;

    if (err == -1) {
        perror("");
        return 84;
    }
    time_t timing = buf.st_mtime;
    char *str = ctime(&timing);
    print_rights(buf);

    my_printf("%lu", buf.st_nlink);
    print_id(buf);

    my_printf("%lu", buf.st_size);
    my_printf(" ");
    my_put_date(str);
    my_printf("%s", dp->d_name);
    my_printf("\n");
    return 0;
}
