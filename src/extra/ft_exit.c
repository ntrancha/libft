/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:56:51 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/24 19:59:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#ifdef STACK_H
# include "../../includes/stack.h"
#endif

void        ft_exit(void)
{
    #ifdef STACK_H
    ft_stack_free();
    #endif
    exit(EXIT_FAILURE);
}
