/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:33:25 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/06 07:00:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H
# include "libft.h"

typedef long long	t_ll;

char	*ft_itoa(int n);
char	*ft_ltoa(long n);
char	*ft_ftoa(float n);
char	*ft_dtoa(double n);
char	*ft_ctos(char c);
int		ft_atoi(const char *str);
int		ft_ltoi(long n);
int		ft_ftoi(float n);
int		ft_dtoi(double n);
int		ft_dectobin(int dec);
int		ft_bintodec(int bin);
char	*ft_dectohex(int dec);
int		ft_hextodec(char *hex);
long	ft_atol(const char *str);
long	ft_itol(int n);
long	ft_dtol(double n);
long	ft_ftol(float n);
t_ll	ft_itoll(int n);
t_ll	ft_ltoll(long n);
t_ll	ft_dtoll(double n);
t_ll	ft_ftoll(float n);
t_ll	ft_atoll(const char *str);
float	ft_atof(const char *str);
float	ft_itof(int n);
float	ft_ltof(long n);
float	ft_dtof(double n);
float	ft_fround(float n, int p);
double	ft_atod(const char *str);
double	ft_itod(int n);
double	ft_ltod(long n);
double	ft_ftod(float n);

#endif
