/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:04:32 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/12 09:54:15 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/opt.h"
#include "../../includes/stack.h"
#include "../../includes/list.h"

int         ft_main(void);

static int  ft_lenint(int cp)
{
    int     nblen;

    if (cp == 0)
        return (1);
    nblen = 0;
    while (cp != 0)
    {
        nblen++;
        cp = cp / 10;
    }
    return (nblen);
}

static char *ft42_itoa(int n)
{
    int     nblen;
    int     sign;
    char    *res;
    t_stacks    *stack;

    if (!(stack = ft_stack_init()))
        return (NULL);    
    sign = (n < 0) ? 1 : 0;
    nblen = ft_lenint(n);
    res = (char *)ft_stack_memalloc(sizeof(char) * (nblen + sign + 1));
    if (res)
    {
        res = res + nblen + sign;
        *res = '\0';
        if (!n)
            *--res = '0';
        while (n != 0)
        {
            *--res = ft_abs(n % 10) + '0';
            n = n / 10;
        }
        if (sign)
            *--res = '-';
    }
    return (res);
}


static void ft_optdel_void(void **opt)
{
    ft_optdel(*opt);
}

int         ft_start(int argc, char **argv)
{
    t_opt   *opt;
    char    *str;
    int     ret;

    ASTR(argv[0], "STR_PROG");
    str = ft42_itoa(ft_getpid());
    CSTR(str, "PID_PROG");
    str = ft42_itoa(ft_getcol());
    CSTR(str, "COL_PROG");
    str = ft42_itoa(ft_getrow());
    CSTR(str, "ROW_PROG");
    str = ft_getpwd();
    CSTR(str, "PWD_PROG");
    if (argc > 1)
    {
        opt = ft_optget(argc, argv);
        ft_vartype_add("ft_opt", ft_liststrsize(opt), ft_optdel_void); 
        ft_calloc(opt, 1, "OPTIONS", "ft_opt");
    }
    ret = ft_main();
    ft_stack_free();
    return (ret);
}
