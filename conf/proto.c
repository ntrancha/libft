/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:50:57 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/05 15:19:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char        *find_pathsrc(void);

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
    char    *src;
    int     len;

    src = find_pathsrc();
    len = ft_strlen(src) + 1;
    ret = ft_strsub(path, len, ft_strlen(path) - len);
    ft_strdel(&src);
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
    if (ft_write_file(header, ret) == 0)
        ft_putendl("_ Réécriture du header");
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
        ft_putstr("La fonction ne correspond pas au nom du fichier : ");
        ft_putendl(path);
    }
    ft_strdel(&cat);
    ft_strdel(&func);
    ft_strdel(&func2);
}

char        *get_function(char *proto)
{
    int     index;
    char    *ret;
    int     start;
    int     end;

    index = -1;
    start = 0;
    end = 0;
    while (proto[++index])
    {
        if (!start && index > 3 && proto[index] == '_')
            if (proto[index - 1] == 't' && proto[index - 2] == 'f')
                start = index - 2;
        if (start && !end && proto[index] == '(')
            end = index;
    }
    ret = ft_strsub(proto, start, end - start);
    return (ret);
}

char        *get_dir(char *header)
{
    int     count;
    int     index;

    index = -1;
    count= 0;
    while (header[++index])
        if (header[index] == '/')
            count = index + 1;
    return (ft_strsub(header, count, ft_strlen(header) - count));
}

void        verif_header(char *dos, char *proto, char *func, char *path)
{
    char    *file;
    char    *cat;
    char    *tmp;

    file = ft_strmmjoin(dos, "/", func, ".c");
    cat = ft_get_file(file);
    if (!cat)
    {
        ft_putstr("Aucun fichier correspondant : ");
        ft_putendl(file);
    }
    tmp = ft_strjoin(func, "(");
    if (ft_strcchr(cat, tmp) == 0)
    {
        ft_putstr("Aucune function correspondante : ");
        ft_putendl(file);
    }
    ft_strdel(&file);
    ft_strdel(&cat);
    ft_strdel(&tmp);
}

void        parse_header(char *header, char *dos)
{
    char    *cat;
    char    *func;
    char    *dir;
    char    **split;
    int     index;

    cat = ft_get_file(header);
    dir = get_dir(dos);
    split = ft_strsplit(cat, '\n');
    index = -1;
    while (split[++index])
    {
        if (ft_strcchr(split[index], ");") && ft_strcchr(split[index], "ft_"))
        {
            func = get_function(split[index]);
            verif_header(dos, split[index], func, header);
            ft_strdel(&func);
        }
    }
    ft_tabstrdel(split);
    ft_strdel(&cat);
    ft_strdel(&dir);
}

void        copy(char *header, char *dos, char *path)
{
    char    *include;

    include = ft_strmmjoin(path, "/includes/", dos, ".h");
    ft_filecopy(header, include);
    ft_strdel(&include);
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
    copy(include2, dos, path);
    ft_strdel(&include);
    ft_strdel(&include2);
}

char        *find_pathsrc(void)
{
    char    **dos;
    int     index;
    int     test;
    
    test = 0;
    index = -1;
    dos = ft_getdirtab_f(".", NULL, 'd');
    while (!test && dos[++index])
        if (ft_strcmp(dos[index], "src") == 0)
            test = 1;
    ft_tabstrdel(dos);
    if (test)
        return (ft_strdup("src"));
    index = -1;
    dos = ft_getdirtab_f("..", NULL, 'd');
    while (!test && dos[++index])
        if (ft_strcmp(dos[index], "../src") == 0)
            test = 1;
    ft_tabstrdel(dos);
    if (test)
        return (ft_strdup("../src"));
    return (NULL);
}

int         main(void)
{
    char    **dos;
    char    *path_src;
    char    *dos_lib;
    char    *path;
    int     index;
    
    path_src = find_pathsrc();
    dos = ft_getdirtab_f(path_src, NULL, 'd');
    path = get_path(path_src);
    index = -1;
    while (dos[++index])
    {
        dos_lib = get_dos(dos[index]);
        next(path, dos_lib, dos[index]);
        ft_strdel(&dos_lib);
    }
    ft_tabstrdel(dos);
    ft_strdel(&path);
    ft_strdel(&path_src);
    return (0);
}
