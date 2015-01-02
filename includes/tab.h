/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:22:33 by ntrancha          #+#    #+#             */
/*   Updated: 2015/01/02 17:22:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H
# include "libft.h"

typedef struct          s_tab
{
    int                 **tab;
    int                 col;
    int                 line;
}                       t_tab;

int     ft_tabmin(t_tab *tab);
int     ft_tabmax(t_tab *tab);
void    ft_tabup(t_tab *tab, int up);
t_tab   *ft_tabdup(t_tab *tab);
int     ft_puttab(t_tab *tab);
void    ft_tabclear(t_tab **tab);
t_tab   *ft_tabdel(t_tab **tab);
t_tab   *ft_tabnew(int line, int col);

#endif
