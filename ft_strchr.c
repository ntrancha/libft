/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:01:05 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/08 16:02:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(char *str, int c)
{
	while (*str != '\0' && *str != (char)c)
		str++;
	if (*str != (char)c)
		return (NULL);
	return (str);
}
