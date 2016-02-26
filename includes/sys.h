/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:35:44 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 16:09:27 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_H
# define SYS_H
# include "libft.h"
# include "stack.h"

# define    START           return (FUNCS(argc, argv));
# define    FUNCS           ft_start
# define    ARGS            int argc, char **argv
# define    MAIN            int main
# define    FT_MAIN         MAIN(ARGS){START}
# define    CACHE_SIZE      1000
# define    DBG_FILE        ft_debug(__FILE__, __func__, __LINE__)
# define    DBG_PROG        ft_sysint_alloc(1, "DBG_PROG")
# define    END_CMD(x)      (x == ' ' || x == ')' || x == ',' || x == '}')

typedef struct  s_funcs     t_funcs;

int     ft_start(int argc, char **argv);
void    ft_cache_set(void *content);
void    ft_sys_option(int argc, char **argv);
void    ft_syslist(void);
void    ft_systabstr(void);
void    ft_sysmem(void);
void    ft_debug(const char *file, const char *func, int line);
void    ft_sysint(void);
void    *ft_sysint_alloc(int num, char *id);
void    ft_sysstr_convert(void);
void    ft_sysconvert(void);
void    ft_sys_fusion(void);
void    ft_syslen(void);
void    *ft_sysfunc_add(char *add, char *name, char *func, void *fptr);
void    ft_sysfunc_init(void);
int     ft_sysfunc_exist(t_funcs *funcs, char *name);
t_funcs *ft_sysfunc_get(char *var_name);
t_funcs *ft_sysfunc_find(t_funcs *funcs, char *name);
void    ft_sys_print(void);
int     ft_syscmd_func(char *str);
int     ft_syscmd_exec(char *var, char *func, char *options);
void    ft_syscmd_echo(char *str);
void    ft_syscmd_addinstruction(char *str);
void    *ft_syscmd(char *str);
int     ft_syscmd_new(char *str);
void    ft_syscmd_sys(char *str);
int     ft_syscmd_base(char *var, char *func, char *options);
int     ft_syscmd_inception(char *var, char *func, char *options);
void    ft_syscmd_file(char *pathfile);
int     ft_syscmd_var(char *str);

#endif
