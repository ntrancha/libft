/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:13:20 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 17:16:00 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "../../includes/file.h"

int             ft_get_timestamp(void)
{
    struct stat s;

    ft_write_file("libft_timestamp", "42");
    lstat("libft_timestamp", &s);
    ft_filedel("libft_timestamp");
    return (s.st_ctime);
}
