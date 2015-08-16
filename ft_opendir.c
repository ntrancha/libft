/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 00:01:25 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 00:09:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <dirent.h>
#include <sys/types.h>

DIR     *ft_opendir(char *path)
{
    DIR *rep;

    if (!path)
        return (0);
    rep = opendir(path);
    if (rep == 0)
        return (0);
    return (rep);
}
