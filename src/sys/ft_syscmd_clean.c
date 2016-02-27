/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:40:34 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/27 19:44:13 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/strings.h"
#include "../../includes/sys.h"


void        ft_syscmd_clean(char **str)
{
    char    *tmp;
    char    *tmp2;

    tmp = ft_strcleanfront(*str, ' ');
    tmp2 = ft_strcleanback(tmp, ' ');
    ft_strdelt(&tmp, str);
    tmp = ft_strcleanfront(tmp2, '\t');
    ft_strdel(&tmp2);
    tmp2 = ft_strcleanback(tmp, '\t');
    ft_strdel(&tmp);
    tmp = ft_strcleanfront(tmp2, ' ');
    ft_strdel(&tmp2);
    tmp2 = ft_strcleanback(tmp, ' ');
    ft_strdel(&tmp);
    *str = ft_strdup(tmp2);
    ft_strdel(&tmp2);
}
