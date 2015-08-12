/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:45:36 by ntrancha          #+#    #+#             */
/*   Updated: 2015/01/13 09:12:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H
# include "libft.h"

# define BUFF_SIZE		100
# define GNL_ILLIMITY	FALSE
# define GNL_FD_MAX		100
# define TRUE			1
# define FALSE			0
# define STDIN			0
# define STDOUT			1
# define STDERR			2
# define MAX_DTOA		10000000000000
# define MAX_FTOA		10000000
# define MAX_INT		2147483648
# define MIN_INT		-2147483647
# define PI				3.141593
# define PHI			1.618032
# define SQUARE2		1.414213
# define RETURN_SUCCES	return (EXIT_SUCCES);
# define RETURN_NULL	return (EXIT_NULL);
# define RETURN_FAIL	return (EXIT_FAIL);
# define RETURN_ERROR	return (EXIT_ERROR);
# define EXIT_SUCCES	1
# define EXIT_NULL		0
# define EXIT_FAIL		-1
# define EXIT_ERROR		-2
# define USER_OS		OS_UNKNOW
# define OS_UNKNOW
# define USER_SYS		SYS_UNKNOW
# define SYS_UNKNOW
# define STR_EMPTY		ft_strdup("")
# define PUT_ENDL		ft_putchar('\n')
# define PUT_ERROR(x)	ft_putstr_fd(x, STDERR)
# define PUT_ERROR_L(x)	ft_putendl_fd(x, STDERR)
# define STR(x)			ft_strdup(#x)
# define CONTENT		ft_listcontent
# define POWER(x, y)	ft_power(x, y)
# define FACTO(x)		ft_facto(x)
# define SQUARE(x)		ft_sqrt(x)
# define ROOT(x)		ft_rsqrt(x)
# define SIN(x)			ft_sin(x)
# define COS(x)			ft_cos(x)
# define TAN(x)			ft_tan(x)
# define ABS(x)			ft_abs(x)
# define NEG(x)			ft_neg(x)

#endif
