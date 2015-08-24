/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_modiftime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:16:18 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:22:19 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/date.h"
#include "../../includes/mem.h"

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
