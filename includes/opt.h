/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 21:01:30 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/04 13:29:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H
# include "list.h"

typedef t_list  t_opt;

t_opt      *ft_optget(int argc, char **argv);
int         ft_isopt(char *option);
void        ft_optdel(t_opt *options);
int         ft_opttest(t_opt *options, char *opt);
char        *ft_optgetopt_simple(t_opt *options, char *opt);
char        *ft_optgetopt_double(t_opt *options, char *opt);
char        *ft_optgetopt_next(t_opt *options);

#endif
