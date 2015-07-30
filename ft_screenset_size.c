/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenset_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:22:58 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 06:26:24 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int             ft_screenset_size(int size)
{
    t_screen    *screen;

    screen = ft_screeninit();
    if (!screen || size < 0)
        return (-1);
    screen->size = size;
    return (size);
}
