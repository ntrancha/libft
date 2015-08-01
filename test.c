/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 03:12:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/01 02:00:49 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    ft_screenwrite_str("ABC", NULL);
    ft_screenset_cursor(0);
    ft_screenwrite_str("x", NULL);
    ft_screenset_cursor(2);
    ft_screenwrite_str("x", NULL);
    ft_screenset_cursor(4);
    ft_screenwrite_str("x", NULL);
    ft_screenprint();
    ft_screenreset();
    ft_screenfull('.', "\033[31m");
    ft_screenprint();
    ft_screenfree();
    //while (1) ;
    return (1);
}
