/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cinstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 14:34:51 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:07:10 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_cinstr(char *str, char c)
{
	int		ret;
	int		index;

	ret = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			ret++;
		index++;
	}
	return (ret);
}
