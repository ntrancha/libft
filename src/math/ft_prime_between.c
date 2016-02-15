/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prime_between.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:21:48 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/15 10:23:56 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_prime_between(int a, int b)
{
    int count;

    count = (a > b) ? b : a;
    while (--count)
        if (b % count == 0 && a % count == 0)
            return (0);
    return (1);
}
