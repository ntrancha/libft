/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_file_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 22:40:05 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 22:57:10 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "includes/libft.h"

int     ft_write_file_end(const char *pathname, char *content)
{
    int fd;

    if (!pathname || !content)
        return (-1);
    fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd < 0)
        return (-1);
    ft_putstr_fd(content, fd);
    ft_putendl(content);
    return (close(fd));
}
