/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclearfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:46:36 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/25 23:13:45 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

void        ft_strclearfront(char **str, char c)
{
    char    *new;

    new = ft_strcleanfront(*str, c);
    ft_strdel(str);
    *str = new;
}
