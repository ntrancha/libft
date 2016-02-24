/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:13:16 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/24 02:52:24 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void        *ft_syscmd(char *str);

int         testb(void *v, void *d)
{
    v = d;
    d = v;
    return (-42);
}

int         testa(void *v)
{
    if (v)
        return (42);
    return (4242);
}

void        testons(char *str)
{
    int     index;

    index = -1;
    while (str[++index])
        if (str[index] != 42)
            ft_putnbr_endl(str[index]);
        else
            ft_putendl("");
    ft_putendl(str);
}

int         ft_syscmd_var(char *str)
{
    char    **tab;
    char    *tmp;
    char    *commande;
    char    *option;
    char    *var;

    tab = ft_strsplit(str, '=');
    var = ft_strcleanback(tab[0], ' ');
    commande = ft_strcleanfront(tab[1], ' ');
    tmp = ft_strsub(commande, 0, ft_strlen(commande) - 1);
    if (tmp[ft_strlen(tmp) - 1] == '(')
        option = ft_strmjoin(tmp, var, ")");
    else                                                    // Ajoute l'assignation en argument
        option = ft_strmmjoin(tmp, ", ", var, ")");
    ft_syscmd(option);                                      // Génére une nouvelle commande
    ft_strdelf(&var, &commande, &tmp, &option);
    ft_tabstrdel(&tab);
    return (0);
}

int         ft_syscmd_base(char *var, char *func, char *options)
{
    int     base;
    char    **tab;

    if (ft_strcchr(options, ",") != 0)
        tab = ft_strsplit(options, ',');
    base = ft_vartype_func(func);
    if (base == 1)
        ft_alloc_del(var);
    if (base == 2)
        ft_alloc_put(var);
    if (base == 3 && options && ft_strcchr(options, ",") == 0)
        ft_alloc_copy(var, options);
    if (base == 4 && options && ft_strcchr(options, ",") == 1)
        ft_sysint_alloc(ft_alloc_cmp(var, tab[0]), tab[1]);
    if (base == 5 && options && ft_strcchr(options, ",") == 1)
        ft_alloc_fusion(var, tab[0], tab[1]);
    if (base == 6 && options && ft_strcchr(options, ",") == 0)
        ft_sysint_alloc(ft_alloc_len(var), options);
    if (base == 7 && options && ft_strcchr(options, ",") == 0)
        ft_sysint_alloc(ft_alloc_count(var), options);
    if (ft_strcchr(options, ",") != 0)
        ft_tabstrdel(&tab);
}

int         ft_syscmd_inception(char *var, char *func, char *options)
{
    char    **tab;
    char    *commande;
    char    *tmp;
    char    *var_tmp;
    int     index;
    int     count;
    int     test;

    tab = NULL;
    index = 0;
    if (ft_strcchr(options, ",") != 0)
    {
        tab = ft_strsplit(options, ',');
        while (tab[index])
        {
            if (ft_strcchr(tab[index], "(") != 0)
            {
                tmp = ft_itoa(index);
                var_tmp = ft_strjoin("TMP_", tmp); 
                commande = ft_strmjoin(var_tmp, " = ", tab[index]);
                ft_syscmd(commande);
                ft_strdelth(&tmp, &var_tmp, &commande);
            }
            index++;
        }
        ft_tabstrdel(&tab);
    }
    else
    {
        tmp = ft_itoa(index);
        var_tmp = ft_strjoin("TMP_", tmp); 
        commande = ft_strmjoin(var_tmp, " = ", options);
        ft_syscmd(commande);
        ft_strdelth(&tmp, &var_tmp, &commande);
    }
    count = -1;
    test = 0;
    commande = ft_strmmjoin(var, " = ", func, "(");
    while (++count < index -1)
    {
        tmp = ft_itoa(count);
        if (!test)
            var_tmp = ft_strmjoin(commande, "TMP_", tmp);
        else
            var_tmp = ft_strmjoin(commande, ", TMP_", tmp);
        ft_strdel(&commande);
        commande = ft_strdup(var_tmp);
        ft_strdelt(&tmp, &var_tmp);
        test++;
    }
    tmp = ft_strjoin(commande, ")");
    ft_strdelt(&tmp, &commande);
    ft_syscmd("TMP_0.del()");
    ft_syscmd("TMP_1.del()");
    ft_syscmd("TMP_2.del()");
    ft_syscmd("TMP_3.del()");
    ft_syscmd("TMP_4.del()");
    return (1);
}

int         ft_syscmd_go_void(t_funcs *funcs, char *var, char **opt)
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

int         ft_syscmd_go_int(t_funcs *funcs, char *var, char **opt)
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
        ft_sysint_alloc(funcs->func->f_int_a(GET(opt1)), opt2);
    else if (ft_strcmp(funcs->func_name, "iv*v*") == 0)
        ft_sysint_alloc(funcs->func->f_int_b(GET(opt1), GET(opt2)), opt3);
    else if (ft_strcmp(funcs->func_name, "iv*v*v*") == 0)
        ft_sysint_alloc(funcs->func->f_int_c(GET(opt1), GET(opt2), GET(opt3)), opt4);
    ft_strdelf(&opt1, &opt2, &opt3, &opt4);
    return (1);
}

int         ft_syscmd_go(t_funcs *funcs, char *var, char **opt)
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
        ft_syscmd_go_int(funcs, var, opt);
    else if (funcs->func_name[0] == 'v' && funcs->func_name[1] == '*')
        ft_syscmd_go_void(funcs, var, opt);
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
        return (ft_syscmd_base(var, func, options));            // FONCTIONS DE BASE
    if (!(funcs = ft_sysfunc_get(var)))
        /*return (0);*/
    ft_putendl("");
    /*if (!(funcs = ft_sysfunc_find(funcs, func)))                // FONCTUIONS EXT
        return (0);*/
    tab = NULL;
    if (ft_strcchr(options, ",") != 0)
        tab = ft_strsplit(options, ',');
    ft_syscmd_go(funcs, var, tab);
    if (tab)
        ft_tabstrdel(&tab);
    return (1);
    
}

void        ft_syscmd_new_other(char *var, char *type, char *content)
{
    char    **tab;

    tab = NULL;
    if (ft_strcmp(type, "tabstr") == 0 || ft_strcmp(type, "liststr") == 0)
    {
        tab = ft_strsplit(content, content[0]);
        ft_alloc(tab, sizeof(char*), var, "tabstr");
        if (ft_strcmp(type, "liststr") == 0)
            ft_alloc_convert(var, type); 
    }
}

int         ft_syscmd_new(char *str)
{
    char    **tab;
    char    **tab2;
    char    *type;
    char    *var;
    char    *content;

    tab = ft_strsplit(str, '=');
    type = ft_strsub(tab[0], 4, ft_strlen(tab[0]) - 5);
    tab2 = ft_strsplit(type, ' ');
    ft_strdel(&type);
    var = ft_strsub(tab2[1], 0, ft_strlen(tab2[1]));
    type = ft_strsub(tab2[0], 0, ft_strlen(tab2[0]));
    content = ft_strsub(tab[1], 1, ft_strlen(tab[1]) - 1);
    if (ft_strcmp(type, "str") == 0)
        ft_calloc(content, ft_strlen(content) + 1, var, type);
    else if (ft_strcmp(type, "int") == 0)
        ft_sysint_alloc(ft_atoi(content), var);
    else
        ft_syscmd_new_other(var, type, content);
    ft_strdelth(&type, &var, &content);
    ft_tabstrdel(&tab);
    ft_tabstrdel(&tab2);
}

int         ft_syscmd_func(char *str)                   // Découpe la commande en
{
    char    *var;                                       // var
    char    *func;                                      // func
    char    *options;                                   // options
    int     index;
    int     count;

    index = 0;
    while (str[index] && (str[index] == ' ' || str[index] == '\t'))
        index++;
    count = index + 1;
    while (str[count] && str[count] != '.')
        count++;
    var = ft_strsub(str, index, count - index); 
    index += ++count;
    while (str[index] && str[index] != '(')
        index++;
    func = ft_strsub(str, count, index - count); 
    count = index++;
    while (str[count] && str[count] != ')')
        count++;
    options = ft_strsub(str, index, ft_strlen(str) - index - 1);
    count = ft_syscmd_exec(var, func, options);             // Traite les 3 parties de la commande
    ft_strdelth(&var, &func, &options);
    return (count);
}

void        *ft_syscmd(char *str)
{
    char    **tab;
    char    *tmp;
    int     index;
    int     ret;

    ret = 0;
    tmp = ft_strcleanfront(str, ' ');
    ft_strdoublon(&tmp, ';');
    if (ft_strcchr(tmp, ";") != 0)
    {
        tab = ft_strsplit(tmp, ';');
        index = -1;
        while (tab[++index])
            ft_syscmd(tab[index]);                      // Excute les commandes multiple
        ft_tabstrdel(&tab);
    }
    else if (ft_strcchr(tmp, "new") != 0 && ft_strcchr(tmp, "(") == 0)
        ret = ft_syscmd_new(tmp);
    else if (ft_strcchr(tmp, "=") == 0)
        ret = ft_syscmd_func(tmp);                  // Traite la commande
    else
        ret = ft_syscmd_var(tmp);                   // Gere l'assigniation
    ft_strdel(&tmp);
    return (str);
}

int         ft_main(void)
{
    size_t  (*ptr)(const char *);
    size_t  (*ptr2)(int);
    char    **tab;

    DBG_FILE;
    DBG_PROG;

    ft_alloc_convert("ft_opt", "int");
    ft_syscmd("new tabstr toto = |42|test|NK|a|z|b|z|s|f|e|a|;");
    ft_syscmd("len = toto.len();");
    ft_syscmd("count = toto.count();");
    ft_syscmd("toto.sort();");
    ptr = &ft_strlen;
    ft_calloc(ptr, 8, "DUMP1", "mem");
    ptr2 = &ft_nbrlen;
    ft_calloc(ptr2, 8, "DUMP2", "mem");
    ft_alloc_fusion("DUMP1", "DUMP2", "DUMP1 + DUMP2");
    ft_stack_infos();
    /*testons("*æ*‰*€*ß*α*⠇*ฆ*☮*♒*♣*⌦*⌥*━*␥*▓*♫*♂");*/
    /*testons("*æ*‰*€*ß*α*⠇*ฆ");*/
    /*ft_putnbr_endl(ft_strlen("*æ*‰*€*ß*α*⠇*ฆ"));*/
    /*ft_putnbr_endl(ft_wstrlen("*æ*‰*€*ß*α*⠇*ฆ"));*/
    return 1;
}

FT_MAIN
