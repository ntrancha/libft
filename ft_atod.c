/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 20:01:08 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/27 20:01:08 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double    atoi_double(char *str, double ret, int signe)
{
    double   index;
    double   tmp;
    
    index = 10;
    if (*str == '.' || *str == ',')
        str++;
    while ((*str >= '0' && *str <= '9'))
    {
        tmp = (*str++ - '0');
        tmp /= index;
        ret += tmp;
        index *= 10;
    }
    return (ret * signe);
}

double       ft_atod(const char *str)
{
    double   ret;
    int     signe;

    ret = 0;
    if (!str)
        return (ret);
    signe = 1;
    while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
            || *str == '\r' || *str == '\v' || *str == '0')
        str++;
    if (*str == '-')
        signe = -1;
    if (*str == '+' || *str == '-')
        str++;
    while ((*str >= '0' && *str <= '9'))
        ret = ret * 10 + (*str++ - '0');
    if (*str == '.' || *str == ',')
        return (atoi_double((char*)str, ret, signe));
    return (ret * signe);
}
