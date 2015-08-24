/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timestamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 05:57:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:24:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/date.h"
#include "../../includes/mem.h"

long        ft_timestamp(char *str)
{
    t_date  *date;
    long    ret;

    date = ft_date_convert(str);
    ret = ft_date_timestamp(date);
    ft_memdel((void*)&date);
    return (ret);
}
