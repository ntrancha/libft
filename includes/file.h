/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:47:17 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 22:51:11 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "libft.h"

int 	ft_gnl(int const fd, char **line);
int 	ft_gnl_list(int const fd, char **line);
int 	ft_readfile(int const fd, char **str);
int	    ft_catfile(const int fd);
char    *ft_get_file(const char *pathname);
int     ft_write_file(const char *pathname, char *content);
int     ft_write_file_end(const char *pathname, char *content);

#endif
