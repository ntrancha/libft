/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 00:55:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 01:04:17 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int ft_socket_read(SOCKET sock, char *buffer)
{
    int n = 0;

    if((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0)
        return (-1);
    buffer[n] = 0;
    return (n);
}
