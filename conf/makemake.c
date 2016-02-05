/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemake.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:33:35 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/05 09:57:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int         test_dos(char *dir)
{
    char    *tmp;
    char    **lib;
    int     index;
    int     test;

    index = -1;
    test = 0;
    lib = ft_getdirtab_f("src", NULL, 'd');
    while (lib[++index])
    {
        tmp = ft_strsub(lib[index], 4, ft_strlen(lib[index])- 4);
        if (ft_strcmp(tmp, dir) == 0)
            test = 1;
        ft_strdel(&tmp);
    }
    ft_tabstrdel(lib);
    if (test == 0)
    {
        ft_putstr(dir);
        ft_putendl(" [not found]");
        return (0);
    }
    return (1);
}

char        *recup_lib(char *include)
{
    int     index;
    int     guill;
    int     slash;
    char    *tmp;

    index = -1;
    guill = 0;
    slash = 0;
    while (include[++index])
        if (include[index] == '"' && guill == 0)
            guill = index;
        else if (include[index] == '/')
            slash = index;
    if (slash > guill)
        guill = slash;
    tmp = ft_strsub(include, guill + 1, ft_strlen(include) - guill);
    tmp[ft_strlen(tmp) - 3] = '\0';
    return (tmp);
}

int         test_lib(char *lib, t_opt *options)
{
    t_node  *node;

    node = options->start;
    while (node)
    {
        if (ft_strcmp(node->content, lib) == 0)
            return (1);
        node = node->next;
    }
    return (0);
}

void        next2(char *ligne, t_opt *options, char *option)
{
    char    *lib;

    lib = recup_lib(ligne);
    if (ft_strcmp(lib, "libft") != 0)
        if (test_lib(lib, options) == 0)
        {
            ft_listadd(options, lib);
            ft_putstr("#include : ");
            ft_putstr(lib);
            ft_putstr(" [");
            ft_putstr(option);
            ft_putendl(".h]");
        }
}

void        next(char *option, t_opt *options)
{
    char    *path;
    char    *cat;
    char    **ligne;
    int     line;

    path = ft_strmjoin("includes/", option, ".h");
    cat = ft_get_file(path);
    ligne = ft_strsplit(cat, '\n');
    line = -1;
    while (ligne[++line])
        if (ft_strcchr(ligne[line], "include \"") != 0)
            next2(ligne[line], options, option);
    ft_strdel(&cat);
    ft_strdel(&path);
    ft_tabstrdel(ligne);
}

void        start(t_opt *options)
{
    t_node  *node;
    t_node  *node2;

    node = options->start;
    while (node)
    {
        node2 = node;
        node = node->next;
        if (test_dos(node2->content))
            next(node2->content, options);
        else
            ft_listdelnode(options, node2, ft_memdel);
    }
}

void        get_all(t_opt *options)
{
    char    **path;
    char    *file;
    int     index;

    path = ft_getdirtab_f("src", NULL, 'd');
    index = -1;
    while (path[++index])
    {
        file = ft_strsub(path[index], 4, ft_strlen(path[index]));
        ft_listadd(options, file);
    }
    ft_tabstrdel(path);
}

void        add_makefile(char *dos, char *func, char *proto, t_list *lst)
{
    if (!proto && func[0] != '.')
    {
        ft_putstr("Prototype not found of ");
        ft_putendl(func);
    }
    else if (func[0] != '.')
        ft_listadd(lst, ft_strdup(dos));
}

void        recup_proto(char *dos, char *cat, char *file, t_list *lst)
{
    char    **ligne;
    int     len;
    int     count;
    char    *proto;
    char    *func;

    ligne = ft_strsplit(cat, '\n');
    count = -1;
    proto = NULL;
    len = ft_strlen(dos) + 5;
    func = ft_strsub(file, len, ft_strlen(file) - len);
    func[ft_strlen(func) - 1] = '\0';
    func[ft_strlen(func) - 1] = '(';
    while (ligne[++count] && !proto)
        if (ft_strcchr(ligne[count], func) != 0)
            proto = ft_strdup(ligne[count]);
    func[ft_strlen(func) - 1] = '\0';
    add_makefile(file, func, proto, lst);
    ft_tabstrdel(ligne);
    ft_strdel(&func);
    ft_strdel(&proto);
}

void        list(t_opt *options, t_list *lst)
{
    t_node  *node;
    char    **dos;
    char    *path;
    char    *cat;
    int     index;

    node = options->start;
    while (node)
    {
        index = -1;
        path = ft_strjoin("src/", node->content);
        dos = ft_getdirtab_f(path, NULL, 'r');
        while (dos[++index])
        {
            cat = ft_get_file(dos[index]);
            recup_proto(node->content, cat, dos[index], lst);
            ft_strdel(&cat);
        }
        node = node->next;
        ft_tabstrdel(dos);
        ft_strdel(&path);
    }
}

void        add_make(t_list *lst)
{
    t_list  *content;
    char    *file;
    char    **ligne;
    int     test;
    int     line;

    file = ft_get_file("Makefile");
    line = -1;
    test = 0;
    ligne = ft_strsplit(file, '\n');
    content = ft_listcreate();
    while (ligne[++line])
    {
        if (ft_strcchr(ligne[line], "FILE ="))
            test = 1;
        if (ft_strcchr(ligne[line], "Windows_NT"))
            test = 2;
        if(test != 1);
            ft_listadd(content, ft_strdup(ligne[line]));
    }
    ft_listputstr(content, ft_putendl);
    ft_strdel(&file);
    ft_tabstrdel(ligne);
}

void        create_make(t_list *lst)
{
    t_node  *node;
    int     len;

    node = lst->start;
    while (node)
    {
        ft_putstr("\t\t");
        ft_putstr(node->content);
        len = ft_strlen(node->content) + 8;
        while (len++ <= 11 * 4)
            ft_putchar(' ');
        ft_putendl("\\");
        node = node->next;
    }
    add_make(lst);
}

int         main(int argc, char **argv)
{
    t_opt   *options;
    t_list  *lst;
    char    *all;
    
    options = ft_optget(argc, argv);
    all = ft_optgetopt_simple(options, "-all");
    lst= ft_listcreate();
    if (all)
        get_all(options);
    else
        start(options);
    list(options, lst);
    create_make(lst);
    ft_strdel(&all);
    ft_optdel(options);
    return (-1);
}
