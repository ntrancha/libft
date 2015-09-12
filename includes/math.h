/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:30:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/12 12:50:22 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;
typedef signed char		t_schar;
typedef signed int		t_sint;
typedef struct          s_point
{
    int                 x;
    int                 y;
}                       t_point;

int	    	ft_abs(int n);
int	    	ft_find_next_prime(int nb);
int	    	ft_neg(int nbr);
int	    	ft_power(int nbr, int power);
int	    	ft_sqrt(int nbr);
int	    	ft_facto(int nb);
long    	ft_abs_long(long n);
long	    ft_neg_long(long nbr);
long long   ft_abs_longlong(long long n);
float	    ft_abs_float(float n);
float   	ft_neg_float(float nbr);
float     	ft_rsqrt(float nb);
float   	ft_cos(float angle);
float   	ft_sin(float angle);
float   	ft_tan(float angle);
double  	ft_abs_double(double n);
double  	ft_neg_double(int nbr);
int	    	ft_nbrcat(int nbr, int nbr2);
t_point     *ft_pointcreate(int x, int y);
char        *ft_sintaddint(char *num, int add); 
char        *ft_addstr(char *a, char *b);
char        *ft_substr(char *a, char *b);
char        *ft_addsubstr(char *a, char *b, int op);

#endif
