/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c   									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:31:34 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/09 12:31:34 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

int			ft_strcchr(char *source, char *search)
{
	int		index;
	int		count;
	int		ret;

	index = 0;
	count = 0;
	ret = 0;
	while (source[index] != '\0')
	{
		if (search[count] == source[index])
			count++;
		else
			count = 0;
		if (search[count] == '\0')
		{
			ret++;
			count = 0;
		}
		index++;
	}
	return (ret);
}
