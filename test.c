/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 11:25:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/05 11:48:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "includes/libft.h"

int         printf_type(char *format, va_list *ap, int count)
{
    int     index;

    if (!(format && format[0] == '%'))
        return (1);
    index = 0;
    while (format[++index])
    {
        if (format[index] == 'd')

        ft_putchar(format[index]);
    }
    return (0);
}

int         ft_printf(char **str, char const *format, ...)
{
    va_list ap;
    int     ret;
    int     count;

    count = 0;
    va_start(ap, format);
    while (*format != 0)
    {
        ret = 1;
        if (*format == '%')
            ret += printf_type((char*)format, &ap, ++count);
        else
            ft_putchar(*format);
        while (ret--)
            *format++;
    }
    va_end(ap);
    return (0);
}

int         main(void)
{
    char    *str;
    int     coucou;
    int     coco;

    coucou = -2;
    coco = 42;
    ft_printf(&str, "%dcoucou%d", coucou, coco);
    return (0);
}
