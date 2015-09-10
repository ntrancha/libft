/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 10:00:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/09/10 21:43:50 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		main(void)
{
	t_bits	*mem;
	char	*str;
	size_t	size;

	str = ft_strdup("Nk42");
	size = sizeof(str);
	mem = ft_bitscreate((void*)str, ft_strlen(str));
    ft_bitssetoctet(mem, 0, ft_sbintocdec("111000"));
    ft_bitssetoctet(mem, 1, 'a');
	ft_putendl(mem->memory);
	ft_strdel(&str);
	ft_bitsdel(mem);
}
