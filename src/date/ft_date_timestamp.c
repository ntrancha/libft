/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_timestamp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:46:21 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/19 06:23:01 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/date.h"
#include "../../includes/mem.h"
#define YEAR    date->year ==

long		days_since_year(t_date *date)
{
	long	ret;
	int		year;

	ret = 0;
	year = date->year;
	while (year > 1970)
		ret += ft_date_diny(--year);
	return (ret);
}

int 		days_since_month(t_date *date)
{
	int		month;
	int		ret;

	month = date->month;
	ret = 0;
	while (--month > 0)
		if (month == 11 || month == 9 || month == 6 || month == 4)
			ret += 30;
		else if (month == 2)
			ret += (ft_date_diny(date->year) == 365) ? 28 : 29;
		else
			ret += 31;
	return (ret);
}

long		ft_date_timestamp(t_date *date)
{
	long	days;
	long	ret;
    int     summer;

	days = (long)date->day - 1;
    summer = ft_date_summertime(date);
	days += (long)days_since_year(date) + (long)days_since_month(date);
	ret = (long)date->seconde + (long)ft_date_mtos(date->minute);
	ret += (long)ft_date_htos(date->hour - 1) + (long)ft_date_dtos(days);
    if (summer == 1)
        ret -= (long)60 * 60;
    if (summer == 2)
        ret += (long)60 * 60;
	return (ret);
}
