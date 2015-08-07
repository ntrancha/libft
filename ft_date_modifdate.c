/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_modifdate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:20:06 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/07 14:22:09 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_date			*ft_date_modifdate(t_date *date, int day, int month, int year)
{
	if (!date)
		date = ft_memalloc(sizeof(t_date));
	if (!date)
		return (date);
	date->day = day;
	date->month = month;
	date->year = year;
	return (date);
}
