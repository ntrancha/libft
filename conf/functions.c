/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:20:49 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/04 15:45:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#define LIBFT	"includes/libft.h"

char		*get_func(char *proto)
{
	int		index;
	int		test;
	int		end;

	index = -1;
	test = 0;
	end = 0;
	while (proto[++index])
	{
		if (!test && index > 4 && proto[index] == '_')
			if (proto[index - 1] == 't' && proto[index - 2] == 'f')
				test = index - 4;
		if (!end && proto[index] == '(')
			end = index;
	}
	return (ft_strsub(proto, test, end - test));
}

void		display(char *proto)
{
	int		index;
	int		count;
	int		test;
	int		cases;

	index = -1;
	test = 0;
	count = 0;
	cases = 1;
	while (proto[++index])
	{
		if (test == 0 && (proto[index] == ' ' || proto[index] == '\t'))
		{
			count = index;
			while (count++ < 13)
				ft_putchar(' ');
			test = 1;
			cases = 10;
		}
		else if (test == 1 && proto[index] != ' ' && proto[index] != '\t')
			test = 2;
		if (proto[index] == '(' && test == 2 && test++ != 0)
			while (cases++ < 35)
				ft_putchar(' ');
		if (test != 1 && cases++)
			ft_putchar(proto[index]);
	}
	ft_putchar('\n');
}

void		parse(char *content, char *search)
{
	char	**ligne;
	char	*func;
	int		line;

	line = -1;
	ligne = ft_strsplit(content, '\n');
	while (ligne[++line])
	{
		if (ft_strcchr(ligne[line], "ft_") != 0)
		if (ft_strcchr(ligne[line], ";") != 0)
		if (ft_strcchr(ligne[line], "#define") == 0)
		if (!search || ft_strcchr(ligne[line], search) != 0)
		{
			if (search)
			{
				func = get_func(ligne[line]);
				if (ft_strcchr(func, search) == 1)
					display(ligne[line]);
				ft_strdel(&func);
			}
			else
				display(ligne[line]);
		}
	}
	ft_tabstrdel(ligne);
}

int			main(int argc, char **argv)
{
	char	**dos;
	char	*content;
	char	*search;
	int		index;

	if (argc == 2)
		search = ft_strdup(argv[1]);
	else
		search = NULL;
	dos = ft_getdirtab_f("includes", NULL, 'r');
	index = -1;
	while (dos[++index])
	{
		if (dos[index][9] != '.' && ft_strcmp(dos[index], LIBFT) != 0)
		{
			content = ft_get_file(dos[index]);
			parse(content, search);
			ft_strdel(&content);
		}
	}
	ft_strdel(&search);
	ft_tabstrdel(dos);
	return (1);
}
