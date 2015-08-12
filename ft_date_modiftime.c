/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_modiftime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:16:18 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/12 21:23:47 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_date  *ft_date_modiftime(t_date *date, int sec, int minute, int hour)
{
	if (!date)
		date = ft_memalloc(sizeof(t_date));
	if (!date)
		return (date);
	date->seconde = sec;
	date->minute = minute;
	date->hour = hour;
	return (date);
}
