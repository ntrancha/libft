/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:14:29 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/18 17:14:32 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H


int     ft_fork(void);
int     ft_fork_goto(void (*parent)(void), void (*child)(void));
int     ft_fork_go(void (*child)(void));

#endif
