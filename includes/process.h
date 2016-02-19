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
int     *ft_pipe(void);
void    ft_pipe_closein(int *tube);
void    ft_pipe_closeout(int *tube);
void    ft_pipe_close_free(int **tube);
int     ft_pipe_dup(int old, int new);
int     ft_fifo_del(char *pathname);
int     ft_fifo_create(char *pathname);

#endif
