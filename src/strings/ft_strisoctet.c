/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisoctet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/09 03:14:16 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/09 03:20:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int         ft_strisoctet(char *str)
{
    int     index;

    index = -1;
    while (str && str[++index] && index < 9)
        if (str[index] != '0' && str[index] != '1')
            return (0);
    if (index != 8)
        return (0);
    return (1);
}
