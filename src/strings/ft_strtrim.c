/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:33:04 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 23:03:07 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		len;
	int		count;
	int		count2;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	new = ft_strnew(len + 1);
	if (!new)
		return (NULL);
	count = 0;
	count2 = 0;
	while (s[count] == ' ' || s[count] == '\t' || s[count] == '\n')
		count++;
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while (count < len)
		new[count2++] = s[count++];
	new[count2] = '\0';
	return (new);
}
