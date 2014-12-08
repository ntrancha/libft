/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 11:00:50 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/01 15:49:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

static int		get_next_line_return(char **str, int ret)
{
	if (ft_strcmp(*str, "FIN") != 0)
	{
		*str = ft_strdup("FIN");
		return (ret);
	}
	return (-1);
}

static int		get_next_line_split(char *all, char **line)
{
	int			index;

	index = 0;
	while (all[index] != '\n' && all[index])
	{
		index++;
	}
	if (!all[index] && !index && all[0] != '\n')
		index = -1;
	ft_strdel(line);
	*line = ft_strsub(all, 0, index);
	return (index);
}

static void		get_next_line_debug(char **str)
{
	int			size;
	char		*tmp;

	tmp = *str;
	size = ft_strlen(tmp);
	if (tmp[size] == '\0' && tmp[size - 1] && tmp[size - 1] == '\n')
	{
		tmp[size] = '\n';
		tmp[size + 1] = '\0';
	}
}

static int		get_next_line_read(int const fd, char **line, char **all)
{
	char		*tmp;
	int			ret;

	ret = BUFF_SIZE;
	tmp = NULL;
	while (ret)
	{
		ft_strdel(line);
		*line = ft_strnew(BUFF_SIZE + 1);
		ret = read(fd, *line, BUFF_SIZE);
		if (ret == -1 || *line == NULL)
			return (-1);
		tmp = ft_strdup(*all);
		ft_strdel(all);
		tmp = ft_strncat(tmp, *line, ret);
		*all = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if (ft_strlen(*line) == 0 && ft_strlen(*all) == 0)
		return (-2);
	ft_strdel(line);
	if (ft_strlen(*all) == 0 || ft_strcmp(*all, "FIN") == 0)
		return (-1);
	get_next_line_debug(all);
	return (0);
}

int				ft_gnl(int const fd, char **line)
{
	static char	*all[100];
	char		*tmp;
	int			ret;

	*line = NULL;
	if (!all[fd])
	{
		all[fd] = ft_strnew(BUFF_SIZE + 1);
		ret = get_next_line_read(fd, line, &all[fd]);
		if (ret == -1)
			return (get_next_line_return(&all[fd], -1));
		if (ret == -2)
			return (get_next_line_return(&all[fd], 0));
	}
	else if (ft_strlen(all[fd]) == 0 || ft_strcmp(all[fd], "FIN") == 0)
		return (-1);
	ret = get_next_line_split(all[fd], line);
	tmp = ft_strsub(all[fd], ret + 1, ft_strlen(all[fd]));
	ft_strdel(&all[fd]);
	all[fd] = ft_strdup(tmp);
	ft_strdel(&tmp);
	if (ft_strlen(all[fd]) == 0)
		return (get_next_line_return(&all[fd], 0));
	return (1);
}
