/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:04:32 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/14 11:59:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sys.h"
#include "../../includes/opt.h"
#include "../../includes/stack.h"
#include "../../includes/list.h"

int         ft_main(void);

static void ft_optdel_void(void **opt)
{
    ft_optdel(*opt);
}

static void ft_syscache(void)
{
    char    *str;

    str = ft_strnew(CACHE_SIZE);
    ASTR(str, "TMP_PROG");
}

static void ft_sysinfo(void)
{
    char    *str;
    char    *path;
    int     test;
    int     count;

    str = ft_itoa(ft_getpid());
    ASTR(str, "PID_PROG");
    str = ft_itoa(ft_getcol());
    ASTR(str, "COL_PROG");
    str = ft_itoa(ft_getrow());
    ASTR(str, "ROW_PROG");
    str = ft_getpwd();
    ASTR(str, "PWD_PROG");
    path = ft_strmjoin(str, "/", GET(STR_PROG));
    count = 0;
    test = 0;
    while (path[++count] && test == 0)
        if (path[count] == '/' && path[count - 1 ] == '.')
            test = count;
    str = ft_strsub(path, test + 1, ft_strlen(path) - test + 1); 
    ASTR(str, "NAM_PROG");
    count = ft_strlen(GET(PWD_PROG)) + 1;
    str = ft_strsub(path, count, ft_strlen(path) - count - ft_strlen(str) - 1); 
    ASTR(str, "DOS_PROG");
    ASTR(path, "DIR_PROG");
}

int         ft_start(int argc, char **argv)
{
    t_opt   *opt;
    int     ret;

    CSTR(argv[0], "STR_PROG");
    if (argc > 1)
    {
        opt = ft_optget(argc, argv);
        ft_vartype_add("ft_opt", ft_liststrsize(opt), ft_optdel_void); 
        ft_alloc(opt, 1, "OPTIONS", "ft_opt");
    }
    ft_sysinfo();
    ft_syscache();
    ret = ft_main();
    ft_stack_free();
    return (ret);
}
