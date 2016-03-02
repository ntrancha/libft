/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_op_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 22:02:21 by ntrancha          #+#    #+#             */
/*   Updated: 2016/03/02 22:06:03 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"

int         ft_syscmd_op_str(char *one, char *two, char *operation)
{
    if (ft_strcmp(operation, "==") == 0 && ft_strcmp(one, two) == 0)
        return (1);
    if (ft_strcmp(operation, "==") == 0 && ft_strcmp(one, two) != 0)
        return (0);
    if (ft_strcmp(operation, "!=") == 0 && ft_strcmp(one, two) == 0)
        return (0);
    if (ft_strcmp(operation, "!=") == 0 && ft_strcmp(one, two) != 0)
        return (1);
    return (0);
}
