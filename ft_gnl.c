/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 11:00:50 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/13 10:31:15 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>

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
tmp = ft_strnew(ft_strlen(*all) + BUFF_SIZE + 1);
ft_strcpy(tmp, *all);
ft_strdel(all);
tmp = ft_strncat(tmp, *line, ret);
*all = ft_strnew(ft_strlen(tmp) + BUFF_SIZE + 2);
ft_strcpy(*all, tmp);
ft_strdel(&tmp);
}
ft_strdel(line);
if (ft_strlen(*all) == 0)
return (-2);
get_next_line_debug(all);
return (0);
}

int				get_next_line_empty(char **line)
{
*line = ft_strdup("");
return (0);
}

int				ft_gnl(int const fd, char **line)
{
	static char	*all[10];
	char		*tmp;
	int			ret;

	if (!all[fd])
	{
		all[fd] = ft_strnew(BUFF_SIZE + 1);
		if ((ret = get_next_line_read(fd, line, &all[fd])) == -1)
			return (-1);
		else if (ret == -2)
			return (get_next_line_empty(line));
	}
	if (all[fd][0] == '\0')
		return (-1);
	ret = get_next_line_split(all[fd], line);
	tmp = ft_strsub(all[fd], ret + 1, ft_strlen(all[fd]));
	ft_strdel(&all[fd]);
	all[fd] = ft_strnew(ft_strlen(tmp) + 1);
	ft_strcpy(all[fd], tmp);
	ft_strdel(&tmp);
	if (all[fd][0] == '\0')
		return (0);
	return (1);
}
