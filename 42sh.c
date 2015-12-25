/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 02:38:53 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/11 02:57:36 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char        *get_commande(void)
{
    int     retour;
    char    *message;

    message = NULL;
    retour = ft_readstdin(&message);
    if (ft_strncmp(message, "exit", 4) == 0)
        return (message);
    ft_putstr(message);
    ft_strdel(&message);
    return (get_commande());
}

int         main(int argc, char **argv)
{
    char    *msg;

    msg = get_commande();
    ft_putendl(msg);
    ft_strdel(&msg);
    return (1);
}
