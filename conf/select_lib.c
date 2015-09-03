/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/31 11:25:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/03 06:50:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/dir.h>
#include <sys/types.h>
#include <sys/stat.h>
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

void		verif_file(char *lib, t_list *files, char **dir, int test)
{
	int		index;
	char	*file;
    char    *src;
    char    *tmp;

	index = -1;
	while (dir[++index])
	{
		file = dir[index];
		if (ft_strlen(file) > 2 && file[ft_strlen(file) - 1] == 'c')
			if (file[ft_strlen(file) - 2] == '.')
			{
				file = ft_strsub(file, 0, ft_strlen(file) - 2);
                tmp = ft_strmjoin("src/", lib, "/");
                src = ft_strmjoin(tmp, file, ".c");
                ft_listadd(files, (void*)src);
				ft_strdel(&file);
				ft_strdel(&tmp);
			}
	}
}

char        *create_dir(char *output, char **lib, int test)
{
    int     index;
    char    *path;
    char    *tmp;

    index = -1;
    if (test == 1)
        path = ft_strdup("../");
    else
        path = ft_strdup("./");
    if (ft_strcmp(output, ".") == 0)
        tmp = ft_strjoin(path, "libft");
    else
        tmp = ft_strmjoin(path, output, "/libft");
    mkdir(tmp, 0777);
    ft_strdel(&path);
    path = ft_strjoin(tmp, "/includes");
    mkdir(path, 0777);
    ft_strdel(&path);
    path = ft_strjoin(tmp, "/src");
    mkdir(path, 0777);
    ft_strdel(&path);
    while (lib[++index])
    {
        path = ft_strmjoin(tmp, "/src/", lib[index]);
        mkdir(path, 0777);
        ft_strdel(&path);
    }
    return (tmp);
}

t_list		*create_makefile(t_list *files, char *path)
{
    t_node  *node;
	t_list	*list;
    char    *file;
    int     max;
    int     size;

    node = files->start;
	list = ft_listcreate();
    max = ft_liststrlenmax(files) + 1;
    while (node)
    {
        file = ft_strdup((char*)node->content);
		size = ft_strlen(file);
		while (size++ < max)
			ft_straddchar(&file, ' ');
		ft_straddchar(&file, '/');
		ft_listadd(list, (void*)file);
        node = node->next;
    }
	return (list);
}

int			ft_count_char(char *str, char c)
{
	int		ret;
	int		count;

	ret = 0;
	count = 0;
	while (str[count])
		if (str[count++] == c)
				ret++;
	return (ret);
}

int 		makefile_add(t_list *makefile, t_list *files)
{
	t_node	*node;
	char	*tmp;
	int		test;

	node = files->start;
	test = 0;
	while (node)
	{
		test++;
		if (test == 1)
			tmp = ft_strjoin("FILE =\t", (char*)node->content);
		else
			tmp = ft_strjoin("\t\t", (char*)node->content);
		ft_listadd(makefile, (void*)tmp);
		node = node->next;
	}
	return (2);
}

void		write_makefile(t_list *makefile, char *path)
{
	char	*file;
	char	*content;

	file = ft_strjoin(path, "/Makefile");
	ft_filedel(file);
	content = ft_listtostrd(makefile, "\n");
    ft_filedel(file);
	ft_write_file(file, content);
	ft_strdel(&file);
	ft_strdel(&content);
}

void		create_makefile_end(t_list *list, char *path, int test)
{
	t_list	*makefile;
	char	*content;
	char	*tmp;
	int		count;
	int		status;
	int		max;

	if (test == 1)
		tmp = ft_strdup("file/Makefile");
	else
		tmp = ft_strdup("conf/file/Makefile");
	content = ft_get_file(tmp);
	makefile = ft_listcreate();
	ft_strdel(&tmp);
	max = ft_count_char(content, '\n');
	count = 0;
	status = 0;
	while (count < max)
	{
		tmp = ft_strgetline(content, count++);
		if (status == 0 && ft_strncmp(tmp, "FILE ", 4) == 0)
			status = 1;
		else if (status == 2 && ft_strlen(tmp) < 5)
			status = 0;
		if (status == 0)
			ft_listadd(makefile, (void*)ft_strdup(tmp));
		else if (status == 1)
			status = makefile_add(makefile, list);
		ft_strdel(&tmp);
	}
	ft_strdel(&content);
	write_makefile(makefile, path);
	ft_listdel(makefile, ft_memdel);
}

void        copy_src(t_list *list, int test, char *path)
{
    t_node  *node;
    char    *src;
    char    *dst;

    node = list->start;
    while (node)
    {
        if (test == 1)
            src = ft_strjoin("../", node->content);
        else 
            src = ft_strdup(node->content);
        dst = ft_strmjoin(path, "/",node->content);
        ft_filecopy(src, dst);
        ft_strdel(&src);
        ft_strdel(&dst);
        node = node->next;
    }
}

void        copy_header(char **lib, int test, char *path)
{
    int     index;
    char    *tmp;
    char    *dst;
    char    *src;

    index = -1;
    while (lib[++index])
    {
		if (ft_strcmp(lib[index], ".") != 0 && ft_strcmp(lib[index], "..") != 0)
        {
            if (test == 1)
                tmp = ft_strmjoin("../src/", lib[index], "/includes/");
            else
                tmp = ft_strmjoin("src/", lib[index], "/includes/");
            src = ft_strmjoin(tmp, lib[index], ".h");
            ft_strdel(&tmp);
            tmp = ft_strmjoin(path, "/includes/", lib[index]);
            dst = ft_strjoin(tmp, ".h");
            ft_filecopy(src, dst);
            ft_strdel(&tmp);
            ft_strdel(&src);
            ft_strdel(&dst);
        }
    }
}

int         add_point_h(t_list *point_h, char **lib)
{
    int     index;
    char    *line;

    index = -1;
    ft_listadd(point_h, ft_strdup(""));
    while (lib[++index])
    {
		if (ft_strcmp(lib[index], ".") != 0 && ft_strcmp(lib[index], "..") != 0)
        {
            line = ft_strmjoin("# include \"", lib[index] ,".h\"");
            ft_listadd(point_h, line);
        }
    }
    return (3);
}

void        write_header(t_list *point_h, char *path)
{
    char    *header;
    char    *content;

    header = ft_strjoin(path, "/includes/libft.h");
    content = ft_listtostrd(point_h, "\n");
    ft_filedel(header);
	ft_write_file(header, content);
    ft_strdel(&header);
    ft_strdel(&content);
}

void        create_header(char **lib, int test, char *path)
{
    char    *header;
    char    *content;
    char    *ligne;
    int     count;
    int     status;
    int     max;
    t_list  *point_h;

    if (test == 1)
        header = ft_strdup("../includes/libft.h");
    else
        header = ft_strdup("includes/libft.h");
    content = ft_get_file(header);
	max = ft_count_char(content, '\n');
	count = -1;
    status = 0;
    point_h = ft_listcreate();
    while (++count < max)
    {
        ligne = ft_strgetline(content, count);
        if (ft_strlen(ligne) < 3)
            status++;
        if (status < 2 || status > 3)
            ft_listadd(point_h, (void*)ft_strdup(ligne));
        else if (status == 2)
            status = add_point_h(point_h, lib);
        ft_strdel(&ligne);
    }
    write_header(point_h, path);
    ft_listdel(point_h, ft_memdel);
    ft_strdel(&header);
    ft_strdel(&content);
}

void        traitement(t_list *files, char **lib, char *output, int test)
{
    char    *path;
	t_list	*list_makefile;

    path = create_dir(output, lib, test);
    list_makefile = create_makefile(files, path);
	create_makefile_end(list_makefile, path, test);
    copy_src(files, test, path);
    create_header(lib, test, path);
    copy_header(lib, test, path);
    ft_strdel(&path);
	ft_listdel(list_makefile, ft_memdel);
}

void		find_file(char **list, char *output)
{
	int		index;
    int     test;
	t_list	*files;
    char    *mini_lib;
	char	**dir;

	index = -1;
    test = test_directory();
	files = ft_listcreate();
	while (list[++index])
	{
		if (ft_strcmp(list[index], ".") != 0 && ft_strcmp(list[index], "..") != 0)
        {
            if (test == 1)
                mini_lib = ft_strmjoin("../src/", list[index], "/");
            else
                mini_lib = ft_strmjoin("src/", list[index], "/");
    		dir = ft_getdirtab(mini_lib, NULL);
			if (dir)
				verif_file(list[index], files, dir, test);
			ft_strdel(&mini_lib);
			if (dir)
				ft_tabstrdel(dir);
		}
	}
    traitement(files, list, output, test);
	ft_listdel(files, ft_memdel);
}

int		main(int argc, char **argv)
{
	t_opt	*options;
	char	*option;
	char	**list_all;
	char	**list;
	char	*output;

    list_all = list_src();
	options = ft_optget(argc, argv);
	option = ft_optgetopt_simple(options, "-l");
	if (option)
	{
		display_list(list_all);
		ft_strdel(&option);
		ft_optdel(options);	
		ft_tabstrdel(list_all);
		return (0);
	}
	option = ft_optgetopt_double(options, "-o");
	if (option)
		output = option;
	else
		output = ft_strdup(".");
    list = recup_list(options, list_all);
    //creation(list, output);
    find_file(list, output);
	ft_tabstrdel(list);
	ft_tabstrdel(list_all);
	ft_optdel(options);	
	ft_strdel(&output);
	return (0);
}
