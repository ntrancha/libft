/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 22:44:59 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/18 22:45:46 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t  ft_strlen(const char *str)
{
    size_t  count;
    count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return (count);
}
