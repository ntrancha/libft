/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:33:04 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/11 13:20:15 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strtrim_end(char *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i)
	{
		s[i] = '\0';
		i--;
	}
	return (s);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		count;
	int		count2;
	int		start;

	if (!s || !*s)
		return (NULL);
	new = ft_strnew(ft_strlen((char*)s));
	count = 0;
	count2 = 0;
	start = 1;
	while (s[count] != '\0')
	{
		if (s[count] != ' ' && s[count] != '\n' && s[count] != '\t' && start)
		{
			start = 0;
		}
		if (!start)
			new[count2++] = s[count];
		count++;
	}
	return (ft_strtrim_end(new));
}
