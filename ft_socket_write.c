/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 00:46:08 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 00:55:05 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int ft_socket_write(SOCKET sock, const char *buffer)
{
    return (send(sock, buffer, strlen(buffer), 0) < 0);
}
