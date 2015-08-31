/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/31 11:25:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/01 01:00:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			test_directory(void)
{
	char	**tab;
	int		index;
	int		test;

	test = 0;
	tab = ft_getdirtab(".", NULL);
	index = 0;
	while (tab[index])
		if (ft_strcmp(tab[index++], "select_lib.c") == 0)
				test = 1;
	ft_tabstrdel(tab);
	tab = ft_getdirtab(".", NULL);
	index = 0;
	while (tab[index])
		if (ft_strcmp(tab[index++], "conf") == 0)
				test = 2;
	ft_tabstrdel(tab);
    tab = ft_getdirtab("..", NULL);
	index = 0;
	while (tab[index])
		if (ft_strcmp(tab[index++], "libft") == 0)
				test = 3;
	ft_tabstrdel(tab);
	return (test);
}

char		**list_src(void)
{
	char	*path;
	char	**tab;

	if (test_directory() == 1)
		path = ft_strdup("../src/");
	else
		path = ft_strdup("src/");
	tab = ft_getdirtab(path, NULL);
	ft_strdel(&path);
	return (tab);
}

void	display_list(char **list)
{
	int index;

	index = -1;
	while (list[++index])
		if (ft_strcmp(list[index], ".") != 0 && ft_strcmp(list[index], "..") != 0)
			ft_putendl(list[index]);
}

int         is_src(char *option, char **src)
{
    int     ret;

    ret = -1;
    while (src[++ret])
        if (ft_strcmp(src[ret], option) == 0)
            return (1);
    return (0);
}

char        **recup_src(t_opt *options, char **src)
{
    t_list  *list;
    char    **tab;
    char    *option;

    list = ft_listcreate();
    option = ft_optgetopt_next(options);
    while (option)
    {
        if (is_src(option, src) == 1)
            ft_listadd(list, (void*)option);
        option = ft_optgetopt_next(options);
    }
    tab = ft_listtotab(list);
    ft_listdel(list, ft_memdel);
    return (tab);
}

char    **recup_list(t_opt *options, char **list_all)
{
	char	*option;
	char	**list;

	option = ft_optgetopt_simple(options, "-a");
	if (!option)
        return (recup_src(options, list_all));
	ft_strdel(&option);
    return (list_src());
}

int         ft_count_char(char *str, char c)
{
    int     index;
    int     ret;

    index = 0;
    ret = 0;
    while (str[index])
        if (str[index++] == c)
            ret++;
    return (ret);
}

t_list      *get_proto(char *content, t_list *list)
{
    int     line;
    int     count;
    char    *ligne;

    line = ft_count_char(content, '\n');
    count = -1;
    while (++count < line)
    {
        ligne = ft_strgetline(content, count);
        if (ft_strcchr(ligne, ";") && ft_strcchr(ligne, "ft_"))
            ft_listadd(list, (void*)ft_strdup(ligne));
        ft_strdel(&ligne);
    }
    return (NULL);
}

int     test_file(char *file, char *path)
{
    char    **dos;
    int     index;
    int     ret;

    dos = ft_getdirtab(path, NULL);
    index = -1;
    ret = 0;
    while (dos[++index])
    {
        if (!ft_strcchr(dos[index], path))
            ret = 1;
    }
    ft_tabstrdel(dos);
    return (ret);
}

void    make_makefile(t_list *protos, int test, char *lib)
{
    t_node  *node;
    t_list  *makefile;
    char    *file;
    char    *src;
    char    *tmp;
    char    *file_ok;
    int     start;
    int     end;

    node = protos->start;
    makefile = ft_listcreate();
    while (node)
    {
        start = 0;
        file = (char*) node->content;
        while (file[start] && file[start] != ' ' && file[start] != '\t')
            start++;
        while (file[start] && (file[start] == ' ' || file[start] == '\t'))
            start++;
        while (file[start] && file[start + 1] && file[start] != 'f' && file[start + 1] != 't')
            start++;
        end = start;
        while (file[end] && file[end] != '(' && file[end] != ';')
            end++;
        file_ok = ft_strsub(file, start, end - start);
        if (test == 1)
            tmp = ft_strmjoin("../src/", lib, "/");
        else
            tmp = ft_strmjoin("src/", lib, "/");
        src = ft_strmjoin(tmp, file_ok, ".c");
        if (test_file(file_ok, tmp))
            ft_listadd(makefile, (void*)src);
        ft_strdel(&tmp);
        ft_strdel(&file_ok);
        node = node->next;
    }
    ft_listdel(makefile, ft_memdel);
}

void    creation(char **list)
{
    char    *mini_lib;
    char    *content;
    t_list  *protos;
    int     index;
    int     test;

    index = -1;
    test = test_directory();
    while (list[++index])
    {
		if (ft_strcmp(list[index], ".") != 0 && ft_strcmp(list[index], "..") != 0)
        {
            protos = ft_listcreate();
            if (test == 1)
                mini_lib = ft_strmjoin("../includes/", list[index], ".h");
            else
                mini_lib = ft_strmjoin("includes/", list[index], ".h");
            content = ft_get_file(mini_lib);
            get_proto(content, protos);
            ft_strdel(&mini_lib);
            ft_strdel(&content);
            make_makefile(protos, test, list[index]);
            ft_listdel(protos, ft_memdel);
        }
    }
}


int		main(int argc, char **argv)
{
	t_opt	*options;
	char	*option;
	char	**list_all;
	char	**list;

    list_all = list_src();
	options = ft_optget(argc, argv);
	option = ft_optgetopt_simple(options, "-l");
	if (option)
	{
		display_list(list_all);
		ft_strdel(&option);
	}
    list = recup_list(options, list_all);
    creation(list);
	ft_tabstrdel(list);
	ft_tabstrdel(list_all);
	ft_optdel(options);	
	return (0);
}
