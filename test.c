/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 03:12:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 07:48:11 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int main (void)
{
    ft_screenwrite_str("J'aime ca\nle", NULL);
    ft_screenwrite_str("s\nponeys", NULL);
    ft_screenwrite_char(' ', NULL);
    ft_screenwrite_char('\n', NULL);
    ft_screenwrite_str("Jaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaazertyuiopazertyuiopaze\nrtyyuiop\n", NULL);
    ft_screenwrite_char('!', NULL);
    ft_screenprint(1);
    return (1);
}
