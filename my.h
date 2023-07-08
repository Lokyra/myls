/*
** EPITECH PROJECT, 2022
** fonction
** File description:
** coder
*/

#ifndef _MY_H_
    #define _MY_H_

    #include <stdarg.h>
    #include <stddef.h>
typedef struct mini_s {
    char *str;
    void (*f) (va_list ap);
} mini_t;

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_st_x(char const *s1, char const *s2, int n, int j);
int my_put_nbr(int nb);
int my_put_double(double a);
int my_printf(const char *format, ...);
int my_put_longdouble(long double a);
int my_put_nbr_base(int nb, char *str);
int my_put_nbr_long_base(long int nb, char *str);
int my_put_nbr_ll_base(long long int nb, char *str);
int my_put_nbr_z_base(size_t nb, char *str);
int my_put_long_nbr(long int a);
int my_put_longlong_nbr(long long int a);
int my_put_z(size_t a);
void my_put_maj_s(char *str);
void flag_f(va_list ap);
void flag_int(va_list ap);
void flag_char(va_list ap);
void flag_str(va_list ap);
void flag_b(va_list ap);
void flag_o(va_list ap);
void flag_u(va_list ap);
int  flag_n(va_list ap, int *a);
void flag_xmin(va_list ap);
void flag_xmaj(va_list ap);
void flag_hashtag_min(va_list ap);
void flag_hashtag_maj(va_list ap);
void flag_hashtag_o(va_list ap);
void flag_maj_s(va_list ap);
void flag_lo(va_list ap);
void flag_lu(va_list ap);
void flag_li(va_list ap);
void flag_lxmin(va_list ap);
void flag_lxmaj(va_list ap);
void flag_llo(va_list ap);
void flag_llu(va_list ap);
void flag_llxmin(va_list ap);
void flag_llxmaj(va_list ap);
void flag_lli(va_list ap);
void flag_zo(va_list ap);
void flag_zu(va_list ap);
void flag_zxmin(va_list ap);
void flag_zxmaj(va_list ap);
void flag_zi(va_list ap);
void flag_ho(va_list ap);
void flag_hu(va_list ap);
void flag_hxmin(va_list ap);
void flag_hxmaj(va_list ap);
void flag_hi(va_list ap);
void flag_ho(va_list ap);
void flag_hu(va_list ap);
void flag_hxmin(va_list ap);
void flag_hxmaj(va_list ap);
void flag_hi(va_list ap);
void flag_hho(va_list ap);
void flag_hhu(va_list ap);
void flag_hhxmin(va_list ap);
void flag_hhxmaj(va_list ap);
void flag_hhi(va_list ap);
int check_error(char flag);
void flag_p(va_list ap);
#endif
