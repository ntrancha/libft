/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 03:57:59 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/29 04:00:26 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>

int                 ft_getrow(void)
{
    struct winsize  w;

    ioctl(0, TIOCGWINSZ, &w);
    return (w.ws_row);
}
