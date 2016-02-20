/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:06:02 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/16 11:09:03 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_tabstrcount(char **tab)
{
    int len;

    if (!tab)
        return (-1);
    len = 0;
    while (tab[len])
        len++;
    return (len);
}