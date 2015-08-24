/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:22:00 by ntrancha          #+#    #+#             */
/*   Updated: 2014/11/19 12:47:31 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int index;

	index = 0;
	if (f && *f)
		if (s && *s)
			while (*s)
			{
				f(index, (char *)s++);
				index++;
			}
}
