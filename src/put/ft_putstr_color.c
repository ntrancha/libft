/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:31:38 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 13:33:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/put.h"

void    ft_putstr_color(char *str, char *color)
{
    ft_putstr(color);
    ft_putstr(str);
    ft_putstr("\033[0m");
}
