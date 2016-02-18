/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 00:02:45 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 00:08:52 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/mem.h"

int     *ft_pipe(void)
{
    int *tube;

    tube = ft_memalloc(sizeof(int) * 2);
    pipe(tube);
    return (tube);
}
