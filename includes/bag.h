/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bag.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 05:39:42 by ntrancha          #+#    #+#             */
/*   Updated: 2015/12/25 08:20:42 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAG_H
# define BAG_H
# include "memory.h"
# include "strings.h"

typedef struct      s_var
{
    void            *content;
    char            *var;
    struct s_var    *next;
    struct s_var    *previous;
}                   t_var;

typedef struct      s_bag
{
    t_var           *start;
    t_var           *end;
    int             size;
}                   t_bag;

t_bag   *ft_bag_create(void);
t_bag   *ft_bag_addvar(t_bag *bag, void *content, char *var);
t_var   *ft_bag_delvar(t_bag *bag, char *var, void(del)(void **));
t_var   *ft_bag_delnode(t_bag *bag, t_var *node, void(del)(void **));
void    ft_bag_del(t_bag *bag, void(del)(void**));
int     ft_bag_content(t_bag *bag, char *var);
void	*ft_bag_get(t_bag *bag, char *var);

#endif
