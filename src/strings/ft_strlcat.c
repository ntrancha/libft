/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:52:32 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:57:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

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
	dest = ft_strnew(chaine + ft_strlen(dst) + 1);
	dest = ft_strncat(dst, source, chaine + 1);
	dst = dest;
	return (taille);
}
