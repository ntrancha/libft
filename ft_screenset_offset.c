/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenset_offset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:22:58 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 06:25:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int             ft_screenset_offset(int offset)
{
    t_screen    *screen;

    screen = ft_screeninit();
    if (!screen || offset < 0)
        return (-1);
    screen->offset = offset;
    return (offset);
}
