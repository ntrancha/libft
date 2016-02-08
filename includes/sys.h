/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:35:44 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/08 15:37:18 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_H
# define SYS_H
# include "libft.h"

# define    START           return (ft_start(argc, argv));
# define    ARGS            int argc, char **argv
# define    MAIN            int main
# define    FT_MAIN         MAIN(ARGS){START}

int         ft_start(int argc, char **argv);

#endif
