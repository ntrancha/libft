/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdirtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 01:14:10 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/03 11:08:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "../../includes/file.h"
#include "../../includes/mem.h"
#include "../../includes/put.h"
#include "../../includes/strings.h"

char        **ft_getdirtab(char *path, char *error)
{
    struct dirent   *file;
    DIR             *rep;
    int             count;
    int             index;
    char            **tab;

    if ((rep = ft_opendir(path, error)) == NULL)
        return (NULL);
    count = 0;
    while ((file = readdir(rep)))
            count++;
    ft_closedir(rep);
    if ((rep = ft_opendir(path, error)) == NULL)
        return (NULL);
    tab = ft_memalloc(sizeof(char*) * (count + 1));
    index = 0;
    while (index < count)
    {
        file = readdir(rep);
        tab[index++] = ft_strdup(file->d_name);
    }
    tab[index] = NULL;
    ft_closedir(rep);
    return (tab);
}
