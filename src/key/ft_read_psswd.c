/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_psswd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:37:09 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 19:46:19 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../includes/file.h"
#include "../../includes/strings.h"

char                *ft_read_psswd(void)
{
    struct termios  t;
    struct termios  old;
    char            *ret;

    if (ioctl(0, TCGETS, &t) < 0)
        return (NULL);
    old = t;
    t.c_lflag &= ~ECHO;
    if (ioctl(0, TCSETS, &t) < 0)
        return (NULL);
    ret = NULL;
    ft_readstdin(&ret);
    if (ioctl(0, TCSETS, &old) < 0)
    {
        ft_strdel(&ret);
        return (NULL);
    }
    return (ret);
}
