/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timestamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 05:57:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/11 06:01:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

long        ft_timestamp(char *str)
{
    t_date  *date;
    long    ret;

    date = ft_date_convert(str);
    ret = ft_date_timestamp(date);
    free(date);
    return (ret);
}
