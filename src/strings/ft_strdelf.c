/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:59:46 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 18:00:26 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void    ft_strdelf(char **a, char **b, char **c, char **d)
{
    ft_strdel(a);
    ft_strdel(b);
    ft_strdel(c);
    ft_strdel(d);
}
