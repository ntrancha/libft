/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 03:12:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/01 14:44:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    ft_screenwrite_charl(1, 'X', C_GREEN);
    ft_screenwrite_str("bABC", NULL);
    ft_screenprint();
    //write(1, "\033[20;1H\b", 7);
    write(1, "\033[H\033[2J", 7);
    //ft_screenclean();
    //ft_screenreset();
    ft_screenfree();
    //while (1) ;
    return (1);
}
