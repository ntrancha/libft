/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/01/06 05:12:55 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

typedef struct  s_alloc t_alloc;
typedef struct  s_vars t_vars;



typedef struct  s_vars
{
    char        *type;
    void        (*del)(void**);
    t_vars      *next;
}               t_vars;

struct          s_alloc
{
    void        *content;
    char        *name;
    size_t      size;
    t_alloc     *next;
    t_alloc     *previous;
};

typedef struct  s_allocs
{
    size_t      stack_size;
    size_t      elements;
    t_alloc     *start;
    t_alloc     *end;
}               t_allocs;



t_alloc      *ft_var_create(void *content, size_t size, void (*del)(void**), char *id);
t_alloc      *ft_var_str(char *content, char *id);
void         ft_var_del(t_alloc *var);




t_alloc      *ft_var_create(void *content, size_t size, void (*del)(void**), char *id)
{
    t_alloc  *var;

    var = ft_memalloc(sizeof(t_alloc));
    if (!var)
        return (NULL);
    var->content = ft_memalloc(size);
    if (!(var->content))
        return (NULL);
    var->content = ft_memmove(var->content, content, size);
    var->size = size;
    var->name = ft_strdup(id);
    var->next = NULL;
    var->previous = NULL;
    return (var);
}

t_alloc      *ft_var_str(char *content, char *id)
{
    t_alloc  *var;

    var = ft_memalloc(sizeof(t_alloc));
    if (!var)
        return (NULL);
    var->content = ft_strdup(content);
    if (!(var->content))
        return (NULL);
    var->size = ft_strlen(content) + 1;
    var->name = ft_strdup(id);
    var->next = NULL;
    var->previous = NULL;
}


int     main(int argc, char **argv)
{
    t_alloc  *str;

    str = ft_var_str("coucou", "A");
    ft_putendl((char*)str->content);
    ft_var_del(str);
    ft_memdel((void**)&str);
    return (1);
}
