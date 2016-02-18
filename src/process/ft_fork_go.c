/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:42:43 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 17:43:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"

int     ft_fork_go(void (*child)(void))
{
    int fork;

    fork = ft_fork();
    if (fork != 0)
        child();
    return (fork);
}
