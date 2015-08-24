/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 22:40:05 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/23 21:39:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../includes/file.h"
#include "../../includes/put.h"

int     ft_write_file(const char *pathname, char *content)
{
    int fd;

    if (!pathname || !content)
        return (-1);
    ft_filedel((char*)pathname);
    fd = open(pathname, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd < 0)
        return (-1);
    ft_putstr_fd(content, fd);
    return (close(fd));
}
