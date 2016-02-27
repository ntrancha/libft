/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:54:10 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/27 20:21:19 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sysfunc.h"
#include "../../includes/sys.h"

void    ft_str_init(void)
{
    ft_sysfunc_add("str", "tolower", "vv*", ft_strtolower_void);
    ft_sysfunc_add("str", "toupper", "vv*", ft_strtoupper_void);
    ft_sysfunc_add("str", "replace", "vv*v*v*", ft_strreplace_void);
}
