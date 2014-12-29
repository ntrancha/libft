/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:37:04 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/29 15:37:04 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const char *str)
{
	long	ret;
	int		signe;

	ret = 0;
	if (!str)
		return (ret);
	signe = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
				|| *str == '\r' || *str == '\v' || *str == '0')
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + (*str++ - '0');
	return (ret * signe);
}
