/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 11:25:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/06 10:44:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../includes/list.h"
#include "../../includes/strings.h"
#include "../../includes/convert.h"
#include "../../includes/mem.h"

static int  strf_add(t_list *list, int ret, char *add)
{
    ft_listadd(list, (void*)add);
    return (ret);
}

static int  strf_float(t_list *list, int ret, double n)
{
    int     index;
    
    if (n < 0)
    {
        ft_listadd(list, (void*)ft_ctos('-'));
        n *= (double)-1.0; 
    }
    ft_listadd(list, (void*)ft_itoa((int)n));
    ft_listadd(list, (void*)ft_ctos('.'));
    n -= (int)n;
    index = 0;
    while (index++ < 6)
        n *= (double)10.0;
    ft_listadd(list, (void*)ft_itoa((int)n));
    return (ret);
}

static int	strf_precis(char *format, int *precis, int *larg, va_list *ap)
{
	int		index;

	index = 0;
	*precis = 0;
	*larg = 0;
	if (format[++index] && format[index] == '*' && index++)
		*larg = va_arg(ap, int);
	else
	{
		while (format[index] && format[index] >= '0' && format[index] <= '9')
			*larg += ((*larg) * 10) + format[index++] - 48;
		if (*larg == 0 && index == 1)
			*larg = -1;
	}
	if (format[index] == '.')
	{
		if (format[++index] && format[index] == '*' && index++)
			*precis = va_arg(ap, int);
		else
			while (format[index] && format[index] >= '0' && format[index] <= '9')
				*precis += ((*precis) * 10) + format[index++] - 48;
	}
	else
		*precis = -1;
	ft_putnbr_endl(*larg);
	ft_putnbr_endl(*precis);
	return (--index);
}

static int  strf_type(char *format, t_list *list, va_list *ap, int index)
{
	int		precis;
	int		larg;

	precis = -1;
	larg = -1;
    if (!(format && format[index++] == '%'))
        return (index);
    if (format[index] == '*' || format[index] == '.')
		index += strf_precis(format, &precis, &larg, ap);
    else if (format[index] >= '0' && format[index] <= '9')
		index += strf_precis(format, &precis, &larg, ap);
	if (format[index] == 'd' || format[index] == 'i')
        return (strf_add(list, index, ft_itoa(va_arg(ap, int))));
    else if (format[index] == 's')
        return (strf_add(list, index, ft_strdup(va_arg(ap, char *))));
    else if (format[index] == 'c')
        return (strf_add(list, index, ft_ctos((char)va_arg(ap, int))));
    else if (format[index] == 'f')
        return (strf_float(list, index, (double)va_arg(ap, double)));
    return (0);
}

char        *ft_strf(char const *format, ...)
{
    va_list ap;
    t_list  *list;
    char    *str;
    int     index;

    list = ft_listcreate();
    va_start(ap, format);
    index = -1;
    while (format[++index])
    {
        if (format[index] == '%')
            index += strf_type((char*)format, list, &ap, 0);
        else
            ft_listadd(list, ft_ctos(format[index]));
    }
    str = ft_listtostr(list);
    ft_listdel(list, ft_memdel);
    va_end(ap);
    return (str);
}
