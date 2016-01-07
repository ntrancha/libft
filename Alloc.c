/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/01/07 06:51:23 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

typedef struct  s_alloc t_alloc;
typedef struct  s_type t_type;
typedef struct  s_stacks t_stacks;

////////////////////////////////////////////////////////////////////////////////

t_type      *ft_vartype_add(t_type *var, char *type, size_t n, void (*del)(void**));
void        ft_vartype_delete(t_type *var);
t_type      *ft_vartype_get(t_type *var, char *type);

t_stacks    *ft_varalloc_init(void);

t_alloc      *ft_var_create(void *content, size_t size, void (*del)(void**), char *id);
t_alloc      *ft_var_str(char *content, char *id);
void         ft_var_del(t_alloc *var);

////////////////////////////////////////////////////////////////////////////////

struct          s_alloc
{
    void        *content;
    t_type      *type;
    char        *name;
    size_t      size;
    t_alloc     *next;
};

struct          s_type
{
    char        *type;
    size_t      n_octet;
    void        (*del)(void**);
    t_type      *next;
};

struct  s_stacks
{
    size_t      stack_size;
    size_t      elements;
    t_type      *types;
    t_alloc     *stack;
};

////////////////////////////////////////////////////////////////////////////////

t_stacks            *ft_varalloc_init(void)
{
    static t_stacks *alloc;

    if (!alloc)
    {
        if (!(alloc = ft_memalloc(sizeof(t_stacks))))
            return (NULL);
        alloc->stack_size = sizeof(t_stacks);
        alloc->elements = 0;
        alloc->stack = NULL;
        alloc->types = ft_vartype_add(NULL, "string", sizeof(char), ft_memdel);
    }
    return (alloc);
}

///////////////////////////////////////////////////////////////////////////////

t_type      *ft_vartype_get(t_type *var, char *type)
{
    if (!var)
        return (NULL);
    while (var)
    {
        if (ft_strcmp(var->type, type) == 0)
            return (var);
        var = var->next;
    }
    return (NULL);
}

t_type      *ft_vartype_add(t_type *var, char *type, size_t n, void (*del)(void**))
{
    t_type  *new;
    t_type  *node;

    if (!type || !del)
        return (NULL);
    if (ft_vartype_get(var, type) != NULL)
        return (var);
    if (!(new = ft_memalloc(sizeof(t_type))))
        return (NULL);
    new->type = ft_strdup(type);
    new->n_octet = n;
    new->del = del;
    new->next = NULL;
    if (!var)
        return (new);
    if (!(node = var->next))
        var->next = new;
    else
    {
        while (node->next)
            node = node->next;
        node->next = new;
    }
    return (var);
}

void        ft_vartype_delete(t_type *var)
{
    t_type  *next;

    if (var)
    {
        next = var->next;
        if (var->type)
            ft_strdel(&(var->type));
        ft_memdel((void**)&var);
        ft_vartype_delete(next);
    }
}

////////////////////////////////////////////////////////////////////////////////

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
}


int     main(int argc, char **argv)
{
    t_type  *vars;
    t_type  *vars2;

    vars = ft_vartype_add(NULL, "a", 1, ft_memdel);
    vars = ft_vartype_add(vars, "b", 1, ft_memdel);
    vars = ft_vartype_add(vars, "c", 1, ft_memdel);
    vars = ft_vartype_add(vars, "b", 1, ft_memdel);
    vars2 = ft_vartype_get(vars, "a");
    ft_putendl(vars2->type);
    ft_vartype_delete(vars);
    return (1);
}
