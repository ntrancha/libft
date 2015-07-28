/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:47:17 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 07:35:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "libft.h"

int 	ft_gnl(int const fd, char **line);
int 	ft_readfile(int const fd, char **str);
int	    ft_catfile(const int fd);
char    *ft_get_file(const char *pathname, int flags);

#endif
