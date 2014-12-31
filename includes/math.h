/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 23:50:33 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/31 23:50:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

int		ft_abs(int n);
int		ft_find_next_prime(int nb);
int		ft_neg(int nbr);
int		ft_power(int nbr, int power);
int		ft_sqrt(int nbr);
int		ft_facto(int nb);
long	ft_abs_long(long n);
long	ft_neg_long(long nbr);
t_ll	ft_abs_longlong(long long n);
float	ft_abs_float(float n);
float	ft_neg_float(float nbr);
float	ft_rsqrt(float nb);
float	ft_cos(float angle);
float	ft_sin(float angle);
float	ft_tan(float angle);
double	ft_abs_double(double n);
double	ft_neg_double(int nbr);

#endif
