/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int my_printf(char const * format, ...)
{
    va_list(paramsinfos);
    va_start(paramsinfos, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            while (format[i] == '%') {
                i++;
                if (format[i] != '%')
                    my_putchar('%');
                while (format[i] != '\0') {
                    my_putchar(format[i]);
                    i++;
                }
                exit( EXIT_SUCCESS );
            }
            while (format[i] >= '0' && format[i] <= '9') {
                my_put_space(i, format);
                i++;
            }
            while (format[i] == ' ') {
                my_putchar(' ');
                i++;
            }
            my_flag(i, paramsinfos, format);
        }
        else {
            my_putchar(format[i]);
        }
    }
    return (0);
}