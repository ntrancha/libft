/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenget_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 06:12:35 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 06:14:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int             ft_screenget_col(void)
{
    t_screen    *screen;

    screen = ft_screeninit();
    if (!screen)
        return (-1);
    return (screen->col);
}
