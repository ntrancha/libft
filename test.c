/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 03:12:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/31 08:40:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int main (void)
{
    ft_screenwrite_str("J'aime ca\nle\tazer\taze\na\taze\taze", NULL);
    //ft_screenwrite_str("s\nponeyssssssssssssssssssssssssssssssssssssssssaaaaaaaaaaaaaaaaaaaaaeaaaaaaaaavaaaaaaaazertyuiopqsdfghjklmwxcvbna\b\bzertyuiopqsdfghA\nAjklmwxcvbn\b", NULL);
    ft_screenwrite_char('!', NULL);
    ft_screenprint();
    ft_screenfree();
    return (1);
}
