/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 03:12:11 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/29 03:56:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/ioctl.h>
#define esc 27
void couleur (char c)     {printf("%c[%dm",esc,c);} /* couleur de 30 a 47 */
void bell (int n) {do         {printf ("%c" , 7) ; n-- ;}   while (n>0) ;}
void bold ()              {printf ("%c[1m",esc) ;} /* -- couleur -- */
void clreol ()            {printf ("%c[0K",esc) ;} /* -- clear eol -- */
void clrscreen ()         {printf ("%c[2J%c[H" , esc , esc) ;}
void cursoff ()           {printf ("%c[?25l",esc) ;}
void curson  ()           {printf ("%c[?25h",esc) ;}
void home ()              {printf ("%c[H",esc)  ;}
void insert ()            {printf ("%c[4h",esc) ;}
void normal ()            {printf ("%c[0;24m",esc) ;}  /* retour de
                                                          bold , overstrike , underline */
void poscur (int l,int c) {printf ("%c[%1d;%1dH" , esc , l , c);}
void replace ()           {printf ("%c[4l",esc) ;}
void underline ()         {printf ("%c[4m",esc) ;}
void videoff ()           {printf ("%c[27m",esc);}
void videon ()            {printf ("%c[7m",esc) ;}
void blink ()             {printf ("%c[5m",esc);}

int main (void)
{
    struct winsize w;
    char    c;
    ioctl(0, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    ft_putnbr(w.ws_row);
    printf ("columns %d\n", w.ws_col);
    printf("Coucou les enfants\n");
    printf("Coucou les enfants\n");
    printf("Coucou les enfants\n");
    printf("Coucou les enfants\n");
    printf("Les systèmes d'exploitation conventionnels divisent la mémoire en 2 espaces, l'espace utilisateur et l'espace noyau. Le code d'une application telle qu'un éditeur de texte réside dans l'espace utilisateur, tandis que les fonctionnalités sous-jacentes du système d'exploitation, telles que la pile réseau, résident dans le noyau. Le code du noyau gère les ressources sensibles et met en œuvre les barrières de sécurité et de fiabilité entre les applications. Pour cette raison, les applications dans l'espace utilisateur ne peuvent pas accéder directement aux ressources du noyau.\n");
    printf("Coucou les enfants\n");
    poscur(1,1);
    write(1, "nk", 2);
    poscur(2,1);
    write(1, "nk", 2);
    poscur(3,1);
    write(1, "nk", 2);
    poscur(1,1);
    c = 27;
    write(1, &c, 1);
    write(1, "[2J", 3);
    write(1, &c, 1);
    write(1, "[H", 3);
    write(1, "\nnkazeazeazeazezaezaezaeazezaezaeazeazeazezaezaeazeazeazeazazeazeazezaezaeooooooeazeaze", 82);
    write(1, &c, 1);
    write(1, "[2J", 3);
    write(1, &c, 1);
    write(1, "[H", 3);
    write(1, "\nnkazeazeazeazezaezaezaeazezaezaeazeazeazezaezaeazeazeazeazeazooooooooooooooooooooooeaze", 82);
    write(1, &c, 1);
    write(1, "[2J", 3);
    write(1, &c, 1);
    write(1, "[H", 3);
    poscur(4,4);
    write(1, "\nnkazeazeazeazezaezaezaeazezaezaeazeazeazezaezaeazeazeazeazeazeazeaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 82);
    write(1, "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bzzzzzzzzzzzzzzzzzzzz", 82);
}
