/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_goto.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:25:47 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 17:29:51 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"

int     ft_fork_goto(void (*parent)(void), void (*child)(void))
{
    int fork;

    fork = ft_fork();
    if (fork == 0)
        parent();
    else
        child();
    return (fork);
}
