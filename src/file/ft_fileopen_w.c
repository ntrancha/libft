/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileopen_w.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 10:06:11 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 10:06:41 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int         ft_fileopen_w(char *pathname)
{
    if (pathname)
        return (open(pathname, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR));
    return (-1);
}
