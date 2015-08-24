/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 00:01:25 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/16 23:29:55 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

DIR     *ft_opendir(char *path, char *error)
{
    DIR *rep;

    if (!path)
        return (0);
    rep = opendir(path);
    if (rep == 0)
    {
        if (error)
            perror(error);
        return (0);
    }
    return (rep);
}
