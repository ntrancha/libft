/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_timestamp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:46:21 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/07 15:26:06 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"



int			days_since_year(t_date *date)
{
	int		ret;
	int		year;

	ret = 0;
	year = date->year;
	while (year > 1970)
		ret += ft_date_diny(--year);
	return (ret);
}

int			days_since_month(t_date *date)
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

int			ft_date_timestamp(t_date *date)
{
	int		days;
	int		ret;

	ret = 0;
	days = date->day - 1;
	days += days_since_year(date);
	days += days_since_month(date);
	ft_putnbr_endl(days);
	ret = date->seconde;
	ret += ft_date_mtos(date->minute);
	ret += ft_date_htos(date->hour - 1);
	ret += ft_date_dtos(days);
	return (ret);
}

int main(void)
{
	t_date	*date;

	date = ft_date_modiftime(date, 0, 0, 1);
	date = ft_date_modifdate(date, 1, 1, 1971);
	ft_putnbr_endl(ft_date_timestamp(date));
		return (1);
}
