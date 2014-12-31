/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 23:52:47 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/31 23:52:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H
# include "libft.h"

void    ft_putnbr_fd(int n, int fd);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char const *s, int fd);
void    ft_putendl_fd(char const *s, int fd);

void    ft_putchar(char c);
void    ft_putstr(char const *str);
void    ft_putendl(char const *s);
void    ft_putnbr(int n);
void    ft_putnbr_endl(int n);
void    ft_putfloat(float n);
void    ft_putlong(long n);
void    ft_putdouble(double n);
void    ft_listputstr(t_list *list, void (put)(char const *));
int     ft_puttab(t_tab *tab);

#endif
