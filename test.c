/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 03:12:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 21:52:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int main (void)
{
    ft_screenwrite_str("J'aime ca\nle", NULL);
    ft_screenwrite_str("s\nponeys\b", NULL);
    ft_screenwrite_char('!', NULL);
    ft_screenprint();
    ft_screenfree();
    return (1);
}
