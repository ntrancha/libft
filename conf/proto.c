/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:50:57 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/04 02:43:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#define DOS_SRC     "../src"

char        *get_path(char *path)
{
    char    *ret;

    if (ft_strcmp(path, "src") == 0)
        return (ft_strdup("."));
    ret = ft_strsub(path, 0, ft_strlen(path) - 4);
    return (ret);
}

char        *get_dos(char *path)
{
    char    *ret;
    int     len;

    len = ft_strlen(DOS_SRC) + 1;
    ret = ft_strsub(path, len, ft_strlen(path) - len);
    return (ret);
}

char        *without_space(char *proto)
{
    char    *ret;
    int     test;
    int     count;
    int     index;

    index = -1;
    count = 0;
    test = 0;
    ret = ft_strnew(ft_strlen(proto) + 1);
    while (proto[++index])
    {
        if (proto[index] != ' ' && proto[index] != '\t')
            test = 0;
        if (test == 0)
        {
            if (proto[index] == '\t')
                ret[count++] = ' ';
            else
                ret[count++] = proto[index];
        }
        if ((proto[index] == ' ' || proto[index] == '\t') && test == 0)
            test = 1;
    }
    return (ret);
}

char        *make_proto(char *proto)
{
    char    *ret;
    int     index;
    int     count;
    int     test;

    index = -1;
    count = 0;
    test = 0;
    ret = ft_strnew(ft_strlen(proto) + 8);
    while (proto[++index])
    {
        if (!test && proto[index] == ' ')
        {
            while (count < 8)
                ret[count++] = ' ';
            test = 1;
        }
        else
            ret[count++] = proto[index];
    }
    ret[count++] = ';';
    ret[count] = '\0';
    ft_strdel(&proto);
    return (ret);
}   

void        add_proto(char *header, char *proto, char *cat)
{
    char    *tmp;
    char    *ret;

    tmp = ft_strsub(cat, 0, ft_strlen(cat) - 8);
    ret = ft_strmjoin(tmp, proto, "\n\n#endif\n");
    ft_strdel(&ret);
    ft_strdel(&tmp);
}

void        test_header(char *proto, char *name, char *header, char *func)
{
    char   *cat;

    cat = ft_get_file(header);
    if (cat && ft_strcchr(cat, func) == 0)
    {
        ft_putstr("dans \"");
        ft_putstr(header);
        ft_putstr("\" fonction manquante : ");
        ft_putendl(name);
        add_proto(header, proto, cat);
    }
    ft_strdel(&cat);
}

void        make_header(char *func, char *file, char *header, char *cat)
{
    char    **ligne;
    int     count;
    char    *test;
    char    *proto;
    char    *name;

    ligne = ft_strsplit(cat, '\n');
    count = -1;
    test = NULL;
    while (ligne[++count] && !test)
        if (ft_strcchr(ligne[count], func) != 0)
            if (ft_strcchr(ligne[count], ";") == 0)
                test = ft_strdup(ligne[count]);
    if (!test)
    {
        ft_putendl("__________ERROR__________");
        ft_putendl(func);
    }
    proto = make_proto(without_space(test));
    name = ft_strsub(file, 0, ft_strlen(file ) - 2);
    test_header(proto, name, header, func);
    ft_strdel(&proto);
    ft_strdel(&test);
    ft_strdel(&name);
    ft_tabstrdel(ligne);
}

void        parse(char *file, char *path, char *header)
{
    char    *cat;
    char    *func;
    char    *func2;

    cat = ft_get_file(path);
    func = ft_strsub(file, 0, ft_strlen(file) - 2);
    func2 = ft_strjoin(func, "(");
    if (ft_strcchr(cat, func2) != 0) 
    {
        make_header(func2, file, header, cat);
    }
    else
    {
        ft_putendl("__________ERROR__________");
        ft_putendl(path);
    }
    ft_strdel(&cat);
    ft_strdel(&func);
    ft_strdel(&func2);
}

void        parse_header(char *header, char *dos)
{
    char    *cat;
    char    **split;
    int     index;

    cat = ft_get_file(header);
    split = ft_strsplit(cat, '\n');
    index = -1;
    ft_putendl(dos);
    while (split[++index])
    {
        if (ft_strcchr(split[index], ");") && ft_strcchr(split[index], "ft_"))
        {
            ft_putendl(split[index]);
        }
    }
    ft_tabstrdel(split);
    ft_strdel(&cat);
}

void        next(char *path, char *dos, char *pathdos)
{
    char    **files;
    char    *file;
    char    *include;
    char    *include2;
    int     index;

    files = ft_getdirtab_f(pathdos, NULL, 'r');
    index = -1;
    include = ft_strmmjoin(path, "/src/", dos, "/includes/");
    include2 = ft_strmjoin(include, dos, ".h");
    while (files[++index])
    {
        file = ft_finpath(files[index]);
        if (file[0] != '.')
            parse(file, files[index], include2);
        ft_strdel(&file);
    }
    ft_tabstrdel(files);
    parse_header(include2, pathdos);
    ft_strdel(&include);
    ft_strdel(&include2);
}

int         main(int argc, char **argv)
{
    t_opt   *options;
    char    **dos;
    char    *dos_lib;
    char    *path;
    int     index;
    
    if ((options = ft_optget(argc, argv)) == NULL)
        return (-1);
    dos = ft_getdirtab_f(DOS_SRC, NULL, 'd');
    path = get_path(DOS_SRC);
    index = -1;
    while (dos[++index])
    {
        dos_lib = get_dos(dos[index]);
        next(path, dos_lib, dos[index]);
        ft_strdel(&dos_lib);
    }
    ft_tabstrdel(dos);
    ft_optdel(options);
    ft_strdel(&path);
    return (1);
}
