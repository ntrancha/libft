/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:35:44 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/17 08:32:55 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_H
# define SYS_H
# include "libft.h"

# define    START           return (FUNCS(argc, argv));
# define    FUNCS           ft_start
# define    ARGS            int argc, char **argv
# define    MAIN            int main
# define    FT_MAIN         MAIN(ARGS){START}
# define    CACHE_SIZE      1000
# define    DEBUG           ft_debug(__FILE__, __func__, __LINE__)

int         ft_start(int argc, char **argv);
void    ft_cache_set(void *content);
void    ft_sys_option(int argc, char **argv);
void    ft_syslist(void);
void    ft_systabstr(void);
void    ft_sysmem(void);
void    ft_debug(const char *file, const char *func, int line);
void    ft_sysint(void);
void    *ft_sysint_alloc(int num, char *id);
void    ft_sysstr_convert(void);

#endif
