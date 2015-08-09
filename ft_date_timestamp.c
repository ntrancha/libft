/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_timestamp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:46:21 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/09 17:24:31 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>


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
        {
			ret += (ft_date_diny(date->year) == 365) ? 28 : 29;
        }
		else
			ret += 31; 
	return (ret);
}

int			ft_date_timestamp(t_date *date)
{
	int		days;
	int		ret;

	days = date->day - 1;
	days += days_since_year(date) + days_since_month(date);
	ret = date->seconde + ft_date_mtos(date->minute);
	ret += ft_date_htos(date->hour - 1) + ft_date_dtos(days);
    free(date);
	return (ret);
}

int main(int argc, char **argv)
{
    t_date  *date;

    date = ft_date_convert("14:42:24 8/9/2015");
    ft_putnbr_endl(ft_date_timestamp(date));
	return (1);
}
