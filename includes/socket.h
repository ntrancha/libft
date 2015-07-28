/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:22:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/28 01:36:54 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_H
# define SOCKET_H
# include <sys/socket.h>
# include <unistd.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "libft.h"
# define closesocket(s)     close(s)
# define BUF_SIZE           1024
# define INVALID_SOCKET     -1
# define SOCKET_ERROR       -1
# define MAX_CLIENTS        100

typedef struct sockaddr_in  SOCKADDR_IN;
typedef struct sockaddr     SOCKADDR;
typedef struct in_addr      IN_ADDR;
typedef int SOCKET;

int     ft_socket_init(void);
SOCKET  ft_socket_init_server(char *port);
SOCKET  ft_socket_init_client(const char *adress, const char *port);
int     ft_socket_write(SOCKET sock, const char *buffer); 
int     ft_socket_read(SOCKET sock, char *buffer);
void    ft_socket_end(void);
void    ft_socket_end_co(SOCKET sock);

#endif
