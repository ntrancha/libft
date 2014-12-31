/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 23:56:27 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/31 23:56:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "libft.h"

int	ft_gnl(int const fd, char **line);
int	ft_gnl_list(int const fd, char **line);
int	ft_readfile(int const fd, char **str);
int	ft_readfilelist(int const fd, t_list *list);
int	ft_catfile_list(const int fd);
int	ft_catfile(const int fd);

#endif
