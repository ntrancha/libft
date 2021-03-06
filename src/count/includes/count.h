/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:39:58 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/06 12:00:15 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_H
# define COUNT_H
# include <stdlib.h>
# include "libft.h"

size_t	ft_strlen(const char *str);
size_t	ft_nbrlen(int nbr);
size_t	ft_floatlenfloat(float n);
size_t	ft_floatlen(float n);
size_t	ft_longlen(long n);
size_t	ft_doublelen(double n);
size_t	ft_doublelendouble(double n);
int		ft_cinstr(char *str, char c);
size_t  ft_tabstrlen(char **str);
int     ft_tabstrcount(char **tab);
size_t  ft_wstrlen(const char *str);

#endif
