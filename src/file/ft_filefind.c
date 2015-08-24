/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filefind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 21:16:37 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/24 21:19:25 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"
#include "../../includes/strings.h"

int         ft_filefind(char *file, char *src)
{
    int     ret;
    char    *content;

    content = ft_get_file(file);
    if (content == NULL)
        return (-1);
   ret = ft_strcchr(content, src);
   ft_strdel(&content);
   return (ret);
}
