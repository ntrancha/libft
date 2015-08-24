/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 00:46:08 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 07:03:31 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/socket.h"
#include "../../includes/count.h"

int ft_socket_write(SOCKET sock, const char *buffer)
{
    return (send(sock, buffer, ft_strlen(buffer), 0) < 0);
}
