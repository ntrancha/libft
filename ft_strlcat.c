/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:52:32 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/10 12:47:20 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dest;
	char	*source;
	size_t	taille;
	int		chaine;

	source = (char *)src;
	taille = ft_strlen(dst);
	if (taille > size)
		return (ft_strlen(source) + size);
	taille = ft_strlen(source) + ft_strlen(dst);
	chaine = size - ft_strlen(dst) - 2;
	if (chaine < 0)
		return (taille);
	dest = malloc(sizeof(char) * chaine + ft_strlen(dst) + 1);
	dest = ft_strncat(dst, source, chaine + 1);
	dst = dest;
	return (taille);
}
