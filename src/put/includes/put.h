/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:32:13 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/04 13:51:22 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H
# include "bits.h"

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putaddr(void *ptr);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putnbr_endl(int n);
void	ft_putfloat(float n);
void	ft_putlong(long n);
void	ft_putdouble(double n);
void	ft_putoctet(t_octet octet);
void	ft_putoctets(t_octet *octet, char del);
void    ft_putbits(t_bits *memory, char del);
void	ft_puthexa(t_octet *octet, char del);
void    ft_putspace(int nbr);
void    ft_putcenter(char *str, int col);
void    ft_putmem(void *mem, int len);

#endif
