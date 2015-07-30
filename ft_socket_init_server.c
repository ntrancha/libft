/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket_init_server.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 01:33:07 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 15:40:28 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

SOCKET ft_socket_init_server(char *port)
{
    SOCKET sock;
    SOCKADDR_IN sin;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
        return (-1);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(ft_atoi(port));
    sin.sin_family = AF_INET;
    if (bind(sock, (SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR)
        return (-1);
    if (listen(sock, MAX_CLIENTS) == SOCKET_ERROR)
        return (-1);
    return sock;
}
