/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileopen_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 09:59:01 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 10:06:16 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int         ft_fileopen_r(char *pathname)
{
    if (pathname)
        return (open(pathname, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR));
    return (-1);
}
