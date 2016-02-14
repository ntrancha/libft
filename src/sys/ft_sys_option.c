/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 22:56:56 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/14 23:12:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"
#include "../../includes/count.h"
#include "../../includes/convert.h"

void        ft_sys_option(int argc, char **argv)
{
    char    *tmp;
    char    *itos;
    int     count;

    count = argc;
    count = 0;
    while (argv[++count])
    {
        itos = ft_itoa(count);
        tmp = ft_strjoin("OPTION_", itos);
        ft_alloc(ft_strdup(argv[count]), ft_strlen(argv[count]), tmp, "str");
        ft_strdel(&tmp);
        ft_strdel(&itos);
    }
}
