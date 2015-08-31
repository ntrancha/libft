/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/31 11:25:47 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/31 23:17:58 by ntrancha         ###   ########.fr       */
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

    display_list(list);
	ft_tabstrdel(list);
	ft_tabstrdel(list_all);
	ft_optdel(options);	
	return (0);
}
