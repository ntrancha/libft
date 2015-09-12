/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sintaddint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 10:41:29 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 11:14:34 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char        *ft_sintaddint(char *num, int add)
{
    char    *ret;
    char    *tmp;

    tmp = ft_itoa(add);
    ret = ft_addstr(num, tmp);
    ft_strdel(&tmp);
    return (ret);
}
