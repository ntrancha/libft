/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filestrrpl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 21:55:06 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/23 22:16:58 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/strings.h"

int         ft_filestrrpl(char *file, char *src, char *mod)
{
    int     ret;
    char    *content;

    content = ft_get_file(file);
    if (content == NULL)
        return (-1);
    ft_strnrpl(&content, src, mod, -1);
    ft_filedel(file);
    ret = ft_write_file(file, content);
    ft_strdel(&content);
    return (ret);
}
