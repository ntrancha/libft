/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:04:32 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 23:09:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/opt.h"
#include "../../includes/stack.h"
#include "../../includes/list.h"

int         ft_main(void);

static void ft_optdel_void(void **opt)
{
    ft_optdel(*opt);
}

int         ft_start(int argc, char **argv)
{
    t_opt   *opt;
    int     ret;

    opt = ft_optget(argc, argv);
    ft_vartype_add("ft_opt", ft_liststrsize(opt), ft_optdel_void); 
    ft_calloc(opt, 1, "OPTIONS", "ft_opt");
    ret = ft_main();
    ft_stack_free();
    return (ret);
}
