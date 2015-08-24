/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 11:52:15 by ntrancha          #+#    #+#             */
/*   Updated: 2015/07/31 12:00:26 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void        ft_signalread(int sig, void(sig_action)(int, siginfo_t*, void*))
{
    struct sigaction    signal;

    signal.sa_sigaction = sig_action;
    signal.sa_flags = 0;
    sigemptyset(&signal.sa_mask);
    sigaction(sig, &signal, 0);
}
