/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:48:19 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/14 23:49:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H
# include "libft.h"
# define SYSTIMER   54000000

int	ft_rgb(int red, int green, int blue);
int ft_getcol(void);
int ft_getrow(void);
int ft_getpid(void);
int ft_test(void);
char    *ft_getpwd(void);
void    ft_timer(int ms);
void    ft_exit(void);

#endif
