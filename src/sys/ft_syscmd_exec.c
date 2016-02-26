/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:18:51 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 15:42:59 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/sys.h"
#include "../../includes/put.h"

static int  ft_syscmd_go_void(t_funcs *funcs, char **opt)
{
    char    *opt1;
    char    *opt2;
    char    *opt3;
    int     test;

    test = (opt && opt[0] && opt[1]);
    opt1 = (opt && opt[0]) ? ft_strcleanfront(opt[0], ' ') : NULL;
    opt2 = (test) ? ft_strcleanfront(opt[1], ' ') : NULL;
    opt3 = (test && opt[2]) ? ft_strcleanfront(opt[2], ' ') : NULL;
    if (ft_strcmp(funcs->func_name, "v*v*") == 0)
        funcs->func->f_voidp_a(GET(opt1));
    else if (ft_strcmp(funcs->func_name, "v*v*v*") == 0)
        funcs->func->f_voidp_b(GET(opt1), GET(opt2));
    else if (ft_strcmp(funcs->func_name, "v*v*v*v*") == 0)
       funcs->func->f_voidp_c(GET(opt1), GET(opt2), GET(opt3));
    ft_strdelth(&opt1, &opt2, &opt3);
    return (1);
}

static int  ft_syscmd_go_int(t_funcs *funcs, char **opt)
{
    char    *opt1;
    char    *opt2;
    char    *opt3;
    char    *opt4;
    int     test;

    test = (opt && opt[0] && opt[1]);
    opt1 = (opt && opt[0]) ? ft_strcleanfront(opt[0], ' ') : NULL;
    opt2 = (test) ? ft_strcleanfront(opt[1], ' ') : NULL;
    opt3 = (test && opt[2]) ? ft_strcleanfront(opt[2], ' ') : NULL;
    opt4 = (test && opt[2] && opt[3]) ? ft_strcleanfront(opt[3], ' ') : NULL;
    if (ft_strcmp(funcs->func_name, "iv*") == 0)
        ft_sysint_alloc(F_INTA(GET(opt1)), opt2);
    else if (ft_strcmp(funcs->func_name, "iv*v*") == 0)
        ft_sysint_alloc(F_INTB(GET(opt1), GET(opt2)), opt3);
    else if (ft_strcmp(funcs->func_name, "iv*v*v*") == 0)
        ft_sysint_alloc(F_INTC(GET(opt1), GET(opt2), GET(opt3)), opt4);
    ft_strdelf(&opt1, &opt2, &opt3, &opt4);
    return (1);
}

static int  ft_syscmd_go(t_funcs *funcs, char *var, char **opt)
{
    char    *opt1;
    char    *opt2;
    char    *opt3;
    int     test;

    test = (opt && opt[0] && opt[1]);
    opt1 = (opt && opt[0]) ? ft_strcleanfront(opt[0], ' ') : NULL;
    opt2 = (test) ? ft_strcleanfront(opt[1], ' ') : NULL;
    opt3 = (test && opt[2]) ? ft_strcleanfront(opt[2], ' ') : NULL;
    if (funcs->func_name[0] == 'i')
        ft_syscmd_go_int(funcs, opt);
    else if (funcs->func_name[0] == 'v' && funcs->func_name[1] == '*')
        ft_syscmd_go_void(funcs, opt);
    else if (ft_strcmp(funcs->func_name, "vv*") == 0)
        funcs->func->f_void_a(GET(var));
    else if (ft_strcmp(funcs->func_name, "vv*v*") == 0)
        funcs->func->f_void_b(GET(opt1), GET(opt2));
    else if (ft_strcmp(funcs->func_name, "vv*v*v*") == 0)
        funcs->func->f_void_c(GET(opt1), GET(opt2), GET(opt3));
    ft_strdelth(&opt1, &opt2, &opt3);
    return (1);
}

int         ft_syscmd_exec(char *var, char *func, char *options)
{
    t_funcs *funcs;
    char    **tab;

    if (ft_strcchr(options, "(") != 0)
        return (ft_syscmd_inception(var, func, options));
    if (ft_vartype_func(func) != 0)
        return (ft_syscmd_base(var, func, options));
    if (!(funcs = ft_sysfunc_get(var)))
        return (0);
    if (!(funcs = ft_sysfunc_find(funcs, func)))
        return (0);
    tab = NULL;
    if (ft_strcchr(options, ",") != 0)
        tab = ft_strsplit(options, ',');
    ft_syscmd_go(funcs, var, tab);
    if (tab)
        ft_tabstrdel(&tab);
    return (1);
}
