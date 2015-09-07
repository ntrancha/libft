/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/06 21:00:48 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libft.h"

int		main(void)
{
	int nbre = 15;
	char *chaine = "Le langage C";
	long prix = 12.0L;
	long double result = prix * nbre;

	printf("Bonjour\n");
	printf("Nombre %3d  prix %ld Total %9ld\n",nbre, prix, prix * nbre);
	printf("%2s est facile\n", chaine);
	printf("%8.1Lf \n", result);
	printf("%*.*Lf \n", 8, 2, result);  /* equivalent a   %8.2Lf    */
	printf("\n");                     /* affichage du caractère % */
	ft_putendl(ft_strf("%*.4faze", 4, (double)prix));
	return 0;
}
