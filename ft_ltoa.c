/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 21:10:42 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/26 21:10:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char    *ft_ltoa(long n)
{   
    char    *s;
    size_t  len;
    
    if (n == 0)
        return (ft_strdup("0"));
    len = ft_longlen(n);
    if (!(s = (char *) malloc((len + 1) * sizeof(*s))))
        return (NULL);
    if (n < 0)
    {
        s[0] = '-';
        n *= -1;
    }
    s[len] = '\0';
    while (n >= 10)
    {
        s[len - 1] = n % 10 + '0';
        n = n / 10;
        len--;
    }
    s[len - 1] = n + '0';
    return (s);
}
