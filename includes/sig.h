/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 11:37:10 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/31 11:54:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H
# include <signal.h>

int     ft_signalsend(int pid, int sig);
void    ft_signalread(int sig, void(sigaction)(int, siginfo_t*, void*));

#endif
