/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclearback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:36:48 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/25 23:13:57 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

void        ft_strclearback(char **str, char c)
{
    char    *new;

    new = ft_strcleanback(*str, c);
    ft_strdel(str);
    *str = new;
}
