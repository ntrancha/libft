/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:30:09 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/11 10:04:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_strdup(char *str)
{
	char	*new;
	int		count;

	count = 0;
	new = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[count] != '\0')
	{
		new[count] = str[count];
		count++;
	}
	return (new);
}
