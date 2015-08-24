/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:37:03 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/08 16:48:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcpy(char *dst, const char *src)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = dst;
	while (src[count] != '\0')
	{
		ptr[count] = src[count];
		count++;
	}
	ptr[count] = '\0';
	return (dst);
}
