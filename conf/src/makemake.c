/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemake.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:33:35 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 10:35:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
        file = ft_strsub(path[index], 4, ft_strlen(path[index]) - 4);
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

char        *path_make(t_list *lst, char *mini, t_list *content)
{
    int     test;

    test = 0;
    if (mini)
    {
        ft_listadd(content, ft_get_file("conf/files/Makefile_mini_h"));
        ft_listadd(content, ft_listtostrd(lst, "\n"));
        ft_listadd(content, ft_get_file("conf/files/Makefile_mini_t"));
        if (ft_dircreate(mini) == -1)
            return (NULL);
        return (ft_strjoin(mini, "/Makefile"));
    }
    ft_listadd(content, ft_get_file("conf/files/Makefile_full_h"));
    ft_listadd(content, ft_listtostrd(lst, "\n"));
    ft_listadd(content, ft_get_file("conf/files/Makefile_full_t"));
    return (ft_strdup("Makefile"));
}

void        copy_src_lib(char *mini, char *lib)
{
    char    *dos;
    char    **file;
    int     index;

    index = -1;
    dos = ft_strjoin("src/", lib);
    file = ft_getdirtab_f(dos, NULL, 'r');
    ft_strdel(&dos);
    while (file[++index])
    {
        dos = ft_strmjoin(mini, "/", file[index]);
        ft_filecopy(file[index], dos);
        ft_strdel(&dos);
    }
    ft_tabstrdel(file);
}

int         test_include(t_list *options, char *lib)
{
    t_node  *node;

    node = options->start;
    while (node)
    {
        if (ft_strcchr(lib, node->content))
            return (1);
        node = node->next;
    }
    return (0);
}

void        copy_src_includes(char *mini, t_list *options)
{
    char    **file;
    char    *dst;
    int     index;

    file = ft_getdirtab_f("includes", NULL, 'r');
    dst = ft_strjoin(mini, "/includes/libft.h");
    ft_filecopy("includes/libft.h", dst);
    ft_strdel(&dst);
    index = -1;
    while (file[++index])
    {
        dst = ft_strmjoin(mini, "/", file[index]);
        if (test_include(options, file[index]))
            ft_filecopy(file[index], dst);
        ft_strdel(&dst);
    }
    ft_tabstrdel(file);
}

void        copy_src(char *mini, t_list *options)
{
    char    *includes;
    t_node  *node;

    includes = ft_strjoin(mini, "/includes");
    ft_dircreate(includes);
    ft_strdel(&includes);
    includes = ft_strjoin(mini, "/src");
    ft_dircreate(includes);
    ft_strdel(&includes);
    node = options->start;
    while (node)
    {
        includes = ft_strmjoin(mini, "/src/", node->content);
        ft_dircreate(includes);
        ft_strdel(&includes);
        copy_src_lib(mini, node->content);
        node = node->next;
    }
    copy_src_includes(mini, options);
}

void        add_make(t_list *lst, char *mini, t_list *options)
{
    t_list  *content;
    char    *file;
    char    *path;

    content = ft_listcreate();
    path = path_make(lst, mini, content);
    file = ft_listtostrd(content, "\n");
    if (path)
    {
        ft_write_file(path, file); 
        if (mini)
            copy_src(mini, options);
    }
    else
        ft_putendl("Create directory : FAIL");
    ft_strdel(&path);
    ft_strdel(&file);
    ft_listdel(content, ft_memdel);
}

void        create_make(t_list *lst, char *mini, t_list *options)
{
    t_node  *node;
    char    *new;
    char    *tmp;
    int     len;

    node = lst->start;
    while (node)
    {
        if (node == lst->start)
            tmp = ft_strjoin("FILE\t=\t", node->content);
        else
            tmp = ft_strjoin("\t\t\t", node->content);
        len = ft_strlen(node->content) + 8;
        while (len++ <= 11 * 4)
        {
            new = ft_strjoin(tmp, " ");
            ft_strdel(&tmp);
            tmp = ft_strdup(new);
            ft_strdel(&new);
        }
        new = ft_strjoin(tmp, "\\");
        ft_strdel((char**)&(node->content));
        node->content = new;
        ft_strdel(&tmp);
        node = node->next;
    }
    add_make(lst, mini, options);
}

int         main(int argc, char **argv)
{
    t_opt   *options;
    t_list  *lst;
    char    *all;
    char    *mini;
    
    options = ft_optget(argc, argv);
    all = ft_optgetopt_simple(options, "-all");
    mini = ft_optgetopt_double(options, "-mini");
    lst= ft_listcreate();
    if (all)
        get_all(options);
    else
        start(options);
    list(options, lst);
    create_make(lst, mini, options);
    ft_strdel(&all);
    ft_strdel(&mini);
    ft_optdel(options);
    return (0);
}
