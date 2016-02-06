/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:20:49 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 16:45:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#define LIBFT	"../includes/libft.h"
#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define PURPLE  "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[1;37m"
#define ZBLACK  "\033[0;30m"
#define ZRED    "\033[0;31m"
#define ZGREEN  "\033[0;32m"
#define ZYELLOW "\033[0;33m"
#define ZBLUE   "\033[0;34m"
#define ZPURPLE "\033[0;35m"
#define ZCYAN   "\033[0;36m"
#define ZGREY   "\033[0;37m"

#define DEFAULT_COLOR "\033[0;m"

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

char        *ret_type(char *proto)
{
    char    *ret;
    char    *type;
    int     index;
    int     start;

    index = 2;
    start = 0;
    while (proto[++index] && start == 0)
        if (proto[index] == '_')
            if (proto[index - 1] == 't')
                if (proto[index - 2] == 'f')
                    start = index - 2;
    ret = ft_strsub(proto, 0, start);
    while (--start > 0)
        if (ret[start] == ' ' || ret[start] == '\t' || ret[start] == '*')
            ret[start] = '\0';
        else
            start = 0;
    type = ft_strmjoin(GREEN, ret, DEFAULT_COLOR);
    ft_strdel(&ret);
    return (type);
}

char        *ret_func(char *proto)
{
    int     index;
    int     start;
    int     end;
    char    *ret;
    char    *func;

    index = 2;
    start = 0;
    end = 0;
    while (proto[++index] && start == 0)
        if (proto[index] == '_')
            if (proto[index - 1] == 't')
                if (proto[index - 2] == 'f')
                    start = index - 2;
    while (proto[++index] && end == 0)
        if (proto[index] == '(')
            end = index;
    ret = ft_strsub(proto, start, end - start);
    func = ft_strmjoin(BLUE, ret, DEFAULT_COLOR);
    ft_strdel(&ret);
    return (func);
}

char        *ret_ptr(char *proto)
{
    int     index;
    int     start;

    index = 2;
    start = 0;
    while (proto[++index] && start == 0)
        if (proto[index] == '_')
            if (proto[index - 1] == 't')
                if (proto[index - 2] == 'f')
                    start = index - 2;
    if (proto[start - 1] == '*' && proto[start - 2] == '*')
    {
        if (proto[start - 3] == '*')
            return (ft_strdup("***"));
        else
            return (ft_strdup(" **"));
    }
    else
        return (ft_strdup("  *"));
    return (NULL);    
}

char        *ret_typeopt(char *option)
{
    int     index;
    int     space;
    char    *ret;
    char    *tmp;

    index = -1;
    space = 0;
    while (option[++index])
        if (option[index] == ' ')
            space = index;
    tmp = ft_strsub(option, 0, space);
    ret = ft_strmjoin(GREEN, tmp, DEFAULT_COLOR);
    ft_strdel(&tmp);
    return (ret);
}

char        *ret_argopt(char *option)
{
    int     index;
    int     space;

    index = -1;
    space = 0;
    while (option[++index])
        if (option[index] == ' ')
            space = index;
    return (ft_strsub(option, space, ft_strlen(option) - space));
}


void		display_next(char *options)
{
    char    **option;
    char    *type;
    char    *arg;
    int     index;

    index = -1;
    option = ft_strsplit(options, ',');
    while (option[++index])
    {
        if (ft_strcmp(option[index], "void") != 0)
        {
            type = ret_typeopt(option[index]);
            arg = ret_argopt(option[index]);
            ft_putstr(type);
            ft_putstr(arg);
            ft_strdel(&type);
            ft_strdel(&arg);
        }
        else
            ft_putstr("\033[1;32mvoid\033[0;m");
        if (option[index + 1])
            ft_putchar(',');
    }
    ft_tabstrdel(option);
}

void		display_opt(char *proto)
{
    int     index;
    int     start;
    char    *option;

    index = 5;
    start = 0;
    ft_putstr("(");
    while (proto[++index] && start == 0)
        if (proto[index] == '(')
            start = index + 1;
    option = ft_strsub(proto, start, ft_strlen(proto) - start - 2);
    display_next(option);
    ft_putendl(");");
    ft_strdel(&option);
}

void		display(char *proto)
{
    char    *ret;
    char    *ptr;
    int     index;
    char    *func;

    ret = ret_type(proto);
    func = ret_func(proto);
    ft_putstr(ret);
    index = ft_strlen(ret);
    while (++index < 28)
        ft_putchar(' ');
    ptr = ret_ptr(proto);
    if (ptr)
        ft_putstr(ptr);
    else
        ft_putstr("   ");
    ft_putstr(func);
    index = ft_strlen(func);
    while (++index < 38)
        ft_putchar(' ');
    display_opt(proto);
    ft_strdel(&ptr);
    ft_strdel(&func);
    ft_strdel(&ret);
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
