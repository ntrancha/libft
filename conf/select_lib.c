/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/31 11:25:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/02 02:43:14 by ntrancha         ###   ########.fr       */
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
