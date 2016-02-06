/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_change_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 23:40:49 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 10:36:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int         have_proto(char *file, char *func)
{
    char    *path_file;
    char    *content;
    int     ret;

    ret = 0;
    if (ft_strcmp(file, ".") == 0 || ft_strcmp(file, "..") == 0)
        return (0);
    path_file = ft_strjoin("includes/", file);
    if (path_file == NULL)
        return (-1);
    content = ft_get_file(path_file);
    if (content == NULL)
        return (0);
    ret = ft_strcchr(content, func);
    ft_strdel(&path_file);
    ft_strdel(&content);
    return (ret);
}

void        change_header(char *origin, char *change, char *header)
{
    char    *path;
    char    *tmp;

    path = ft_strjoin("includes/", header);
    tmp = ft_strjoin(change, "(");
    ft_filestrrpl(path, origin, tmp);
    ft_strdel(&path);
    ft_strdel(&tmp);
}

char        *find_in_header(char *origin, char *change)
{
    int     ret;
    int     index;
    char    *header;
    char    **tab;

    ret = 0;
    index = -1;
    tab = ft_getdirtab("includes", NULL);
    if (tab == NULL)
        return (NULL);
    while (tab[++index] && ret == 0)
        ret = have_proto(tab[index], origin);
    if (ret == 0)
    {
        ft_tabstrdel(tab);
        return (NULL);
    }
    header = ft_strsub(tab[index - 1], 0, ft_strlen(tab[index - 1]) - 2);
    change_header(origin, change, tab[index - 1]);
    ft_tabstrdel(tab);
    return (header);
}

void        modif_src2(char *proto, char *proto_modif, char *file)
{
    char    **dos;
    char    *src;
    char    *tmp;
    char    *content;
    int     index;

    src = ft_strjoin("src/", file);
    ft_putendl("ok");
    dos = ft_getdirtab(src, NULL);
    index= -1;
    while (dos[++index])
        if (ft_strcmp(dos[index], ".") != 0 && ft_strcmp(dos[index], "..") != 0)
            if (ft_strcmp(dos[index], "includes") != 0)
                if (dos[index][ft_strlen(dos[index]) - 1] == 'c')
                {
                    tmp = ft_strmjoin(src, "/", dos[index]);
                    content = ft_get_file(tmp);
                    if (ft_strcchr(content, proto) != 0)
                        ft_filestrrpl(tmp, proto, proto_modif);
                    ft_strdel(&tmp);
                    ft_strdel(&content);
                }
    ft_strdel(&src);
    ft_tabstrdel(dos);
}

void        modif_src(char *proto, char *proto_modif)
{
    char    **dos;
    int     index;

    dos = ft_getdirtab("src", NULL);
    index= -1;
    while (dos[++index])
        if (ft_strcmp(dos[index], ".") != 0 && ft_strcmp(dos[index], "..") != 0)
            modif_src2(proto, proto_modif, dos[index]);
    ft_tabstrdel(dos);
}

int         find_proto(char *src, char *header, char *origin, char *change)
{
    char    *path;
    char    *tmp;
    char    *path_mod;
    char    *tmp_mod;
    char    *titre;
    char    *titre_change;
    char    *proto;
    char    *proto_change;

    tmp = ft_strjoin("/", src);
    path = ft_strmjoin("src/", header, tmp);
    tmp_mod = ft_strmjoin("/", change, ".c");
    path_mod = ft_strmjoin("src/", header, tmp_mod);
    titre = ft_strjoin(origin, ".c");
    titre_change = ft_strjoin(change, ".c");
    while (ft_strlen(titre) > ft_strlen(titre_change))
        ft_straddchar(&titre_change, ' ');
    while (ft_strlen(titre) < ft_strlen(titre_change))
        ft_straddchar(&titre, ' ');
    proto = ft_strjoin(origin, "(");
    proto_change = ft_strjoin(change, "(");
    ft_filestrrpl(path, titre, titre_change);
    ft_filestrrpl(path, proto, proto_change);
    ft_filemove(path, path_mod);
    modif_src(proto, proto_change);
    ft_strdel(&tmp);
    ft_strdel(&tmp_mod);
    ft_strdel(&path);
    ft_strdel(&path_mod);
    ft_strdel(&titre_change);
    ft_strdel(&titre);
    ft_strdel(&proto_change);
    ft_strdel(&proto);
    return (0);
}

int         init(char *origin, char *change)
{
    char    *test_proto;
    char    *proto;
    char    *src;


    proto = ft_strjoin(origin, "(");
    src= ft_strjoin(origin, ".c");
    test_proto = find_in_header(proto, change);
    if (test_proto == NULL)
        return (-1);
    find_proto(src, test_proto, origin, change);
    ft_strdel(&proto);
    ft_strdel(&test_proto);
    ft_strdel(&src);
    return (1);
}


int         main(int argc, char ** argv)
{
    t_opt   *options;
    char    *origin;
    char    *change;

    if (argc != 3)
        return (0);
    options = ft_optget(argc ,argv);
    origin = ft_optgetopt_next(options);
    change = ft_optgetopt_next(options);
    init(origin, change);
    ft_strdel(&change);
    ft_strdel(&origin);
    ft_optdel(options);
    return (1);
}
