/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscmd_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:00:50 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/26 09:01:37 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/strings.h"
#include "../../includes/file.h"
#include "../../includes/sys.h"

void        ft_syscmd_file(char *pathfile)
{
    char    *file;

    file = ft_get_file(pathfile);
    ft_strnrpl(&file, "\n", ";", -1);
    ft_syscmd_addinstruction(file);
    ft_strdel(&file);
}
