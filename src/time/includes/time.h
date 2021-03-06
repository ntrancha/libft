/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 01:26:21 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 20:12:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H
# include <time.h>

size_t      ft_time(void);
void    ft_sleep(int sec);
int     ft_random(void);
int     ft_rand(int min, int max);
int     ft_get_timestamp(void);
int     ft_random_hundred(void);

#endif
