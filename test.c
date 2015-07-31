/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 03:12:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/31 09:25:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


/* Gestionnaire naif se contentant d'indiquer qu'un signal
   a été reçu accompagné de son numéro */
void handler(int theSignal)
{
    printf("Je receptionne le signal %d\n",theSignal);
    fflush(stdout);
}


int main(void)
{
    /* Déclaration d'une structure pour la mise en place des gestionnaires */
    struct sigaction prepaSignal;

    /* Remplissage de la structure pour la mise en place des gestionnaires */
    /* adresse du gestionnaire */
    prepaSignal.sa_handler=&handler;
    /* Mise a zero du champ sa_flags theoriquement ignoré*/
    prepaSignal.sa_flags=0;
    /* On ne bloque pas de signaux spécifiques */
    sigemptyset(&prepaSignal.sa_mask);

    /* Mise en place du gestionnaire bidon pour trois signaux */
    sigaction(SIGINT,&prepaSignal,0);
    sigaction(SIGQUIT,&prepaSignal,0);
    sigaction(SIGTERM,&prepaSignal,0);
    sigaction(SIGKILL,&prepaSignal,0);
    ft_screenwrite_str("J'aime ca\nle\tazer\taze\na\taze\taze", NULL);
    //ft_screenwrite_str("s\nponeyssssssssssssssssssssssssssssssssssssssssaaaaaaaaaaaaaaaaaaaaaeaaaaaaaaavaaaaaaaazertyuiopqsdfghjklmwxcvbna\b\bzertyuiopqsdfghA\nAjklmwxcvbn\b", NULL);
    ft_screenwrite_char('!', NULL);
    ft_screenprint();
    ft_screenfree();
    //while (1) ;
    return (1);
}
