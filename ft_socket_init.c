/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 01:04:28 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 01:08:41 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int ft_socket_init(void)
{
    #ifdef WIN32
        WSADATA wsa;
        return (WSAStartup(MAKEWORD(2, 2), &wsa));
    #endif
    return (1);
}
