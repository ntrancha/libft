/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getkey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:11:58 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 16:37:49 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

char                *ft_getkey(void)
{
    struct termios  t;
    char            *buffer;

    buffer = malloc((sizeof(char) * 4));
    buffer[0] = '\0'; 
    buffer[1] = '\0'; 
    buffer[2] = '\0'; 
    buffer[3] = '\0'; 
    if (ioctl(0, TCGETS, &t) < 0)
        return (NULL);
    t.c_lflag &= ~ICANON;
    if (ioctl(0, TCSETS, &t) < 0)
        return (NULL);
    read(0, buffer, 3);
    if (ioctl(0, TCGETS, &t) < 0)
        return (NULL);
    t.c_lflag &= ICANON;
    if (ioctl(0, TCSETS, &t) < 0)
        return (NULL);
    write(1, "\b\b\b\b    \b\b\b\b", 12);
    return (buffer);
}
