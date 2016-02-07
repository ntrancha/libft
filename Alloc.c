/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 20:33:15 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/stack.h"
#define START       return (ft_start(argc, argv));
#define ARGS        int argc, char **argv
#define MAIN        int main
#define FT_MAIN     MAIN(ARGS){START}

int         ft_main(void);

void        ft_optdel_void(void **opt)
{
    ft_optdel(*opt);
}

int         ft_main(void)
{

}

int         ft_start(int argc, char **argv)
{
    t_opt   *opt;

    opt = ft_optget(argc, argv);
    ft_vartype_add("ft_opt", ft_liststrsize(opt), ft_optdel_void); 
    ft_calloc(opt, 1, "OPTIONS", "ft_opt");
    ft_main();
    ft_stack_free();
}

FT_MAIN
