/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 06:41:02 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/03 17:27:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "includes/libft.h"

static int  readfile_next(const int fd, char **str, t_list *list)
{
    char    *line;
    int     ret;
    
    ret = BUFF_SIZE;
    line = NULL;
    while (ret)
    {
        line = ft_strnew(BUFF_SIZE + 2);
        if ( line == NULL || (ret = read(fd, line, BUFF_SIZE)) == -1 )
            return (EXIT_FAIL);
        line[ret] = '\0';
        //while ((int)ft_strlen(line) != ret)
        //    line[ft_strlen(line)] = '\a';
        //*str = ft_ctos('\a');
        //ft_strnrpl(&line, *str, "", -1);
        if (str != NULL)
            ft_strdel(str);
        list = ft_listadd(list, line);
    }
    *str = ft_listtostr(list);
    return (1);
}

static int  readfile_list(const int fd, char **str)
{
    t_list  *list;
    void    (*del)(void **);
    
    list = ft_listcreate();
    if (!list)
        return (EXIT_FAIL);
    del = ft_memdel;
    if (readfile_next(fd, str, list) != 1)
        return (EXIT_FAIL);
    ft_listdel(list, del);
    return (1);
}

char    *ft_get_file(const char *pathname)
{
    int     fd;
    char    *str;

    str = NULL;
    fd = open(pathname, O_RDONLY);
    if (fd < 1)
        return (EXIT_NULL);
    if (readfile_list(fd, &str) != 1)
        return (NULL);
    close(fd);
    return (str);
}
