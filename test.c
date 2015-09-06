/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 11:25:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/06 03:38:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "includes/libft.h"

int         printf_add(t_list *list, int ret, char *add)
{
    ft_listadd(list, (void*)add);
    return (ret);
}

void        test(double n)
{
    int     entier;
    
    entier = (int)n;
    ft_putnbr_endl(entier);
    n -= (int)n; 
}


int         printf_type(char *format, t_list *list, va_list *ap, int count)
{
    int     index;

    if (!(format && format[0] == '%'))
        return (1);
    index = 0;
    if (format[1] == 'd' || format[1] == 'i')
        return (printf_add(list, 1, ft_itoa(va_arg(ap, int))));
    else if (format[1] == 's')
        return (printf_add(list, 1, ft_strdup(va_arg(ap, char *))));
    else if (format[1] == 'c')
        return (printf_add(list, 1, ft_ctos((char)va_arg(ap, int))));
    else if (format[1] == 'f')
        test((double)va_arg(ap, double));
    return (0);
}

char        *ft_printf(char const *format, ...)
{
    va_list ap;
    t_list  *list;
    char    *str;
    int     ret;
    int     count;

    count = 0;
    list = ft_listcreate();
    va_start(ap, format);
    while (*format != 0)
    {
        ret = 1;
        if (*format == '%')
            ret += printf_type((char*)format, list, &ap, ++count);
        else
            ft_listadd(list, ft_ctos(*format));
        while (ret--)
            *format++;
    }
    str = ft_listtostr(list);
    ft_listdel(list, ft_memdel);
    va_end(ap);
    return (str);
}

int         main(void)
{
    char    *str;
    char    *coucou;
    char    *coucou2;
    char    *format;
    char    c;
    int     coco;
    float   un;
    double  deux;

    coucou = ft_strdup("NK");
    coucou2 = ft_strdup("-N-K-");
    format = ft_strdup("%c!%scoucou%i%s\n%f %f");
    coco = 42;
    c = 'Z';
    un = 3.5;
    deux = -.23;
    //str = ft_printf("coucou%d", coco);
    str = ft_printf(format, c, coucou, coco, coucou2, un ,deux);
    ft_putendl(str);
    //printf(format, coucou, c, coco, coucou2, un, deux);
    ft_strdel(&str);
    ft_strdel(&coucou);
    ft_strdel(&coucou2);
    ft_strdel(&format);
    return (0);
}
