/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket_init_client.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 01:21:50 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/30 15:36:30 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

SOCKET  ft_socket_init_client(const char *address, const char *port)
{
    struct hostent  *hostinfo;
    SOCKET          sock;
    SOCKADDR_IN     sin;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
        return (-1);
    hostinfo = gethostbyname(address);
    if (hostinfo == NULL)
        return (-1);
    sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
    sin.sin_port = htons(ft_atoi(port));
    sin.sin_family = AF_INET;
    if (connect(sock, (SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
        return (-1);
    return sock;
}
