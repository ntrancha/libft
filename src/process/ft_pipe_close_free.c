/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_close_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 00:14:47 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/19 00:16:43 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/mem.h"

void    ft_pipe_close_free(int **tube)
{
    close(*tube[0]);
    close(*tube[1]);
    ft_memdel((void**)tube);
}
