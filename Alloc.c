/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/01/07 17:33:11 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

typedef struct  s_alloc t_alloc;
typedef struct  s_type t_type;
typedef struct  s_stacks t_stacks;
/* ************************************************************************** */
#define  GET(variable) ft_alloc_vget(#variable)
#define  DEL(variable) ft_alloc_del(#variable)
#define  PDEL(variable) ft_alloc_pdel(variable)
#define  XSTR(var, name) ft_alloc(#var, ft_strlen(#var) + 1, #name, "str")
/* ************************************************************************** */
t_type          *ft_vartype_init(void);
t_type          *ft_vartype_add(char *type, size_t n, void (*del)(void**));
void            *ft_vartype_delete(t_type *var);
t_type          *ft_vartype_get(char *type);
                /* STACK */
t_stacks        *ft_stack_init(void);
void            *ft_stack_free(void);
void            ft_stack_infos(void);
void            *ft_stack_clean(void);
void            *ft_stack_free(void);
                /* ALLOC */
void            *ft_malloc(size_t len);
void            *ft_calloc(void *var, size_t len, char *id, char *type);
void            *ft_alloc(void *var, size_t len, char *id, char *type);
t_alloc         *ft_alloc_get(char *id);
void            *ft_alloc_vget(char *id);
static void     *ft_alloc_delete(t_alloc *alloc);
void            *ft_alloc_copy(char *id, char *new);
void            *ft_alloc_pdel(void *content);
t_stacks        *ft_alloc_del(char *id);
/* ************************************************************************** */

struct          s_alloc
{
    void        *content;
    char        *type;
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
    size_t      sys;
    size_t      free;
    t_type      *types;
    t_alloc     *alloc;
};

/* ************************************************************************** */

static char     *ft_stack_randomid(void)
{
    static int  id_rand;

    id_rand++;
    return (ft_itoa(id_rand));
}

static void     *ft_stack_memmove(void *dst, void *src, size_t len)
{
    void        *ptr;
    t_stacks    *stack;

    ptr = ft_memmove(dst, src, len);
    stack = ft_stack_init();
    stack->sys += len;
    return (ptr);
}

static void     *ft_stack_memalloc(size_t size)
{
    void        *ptr;
    t_stacks    *stack;

    ptr = ft_memalloc(size);
    stack = ft_stack_init();
    stack->sys += size;
    return (ptr);
}

static void     *ft_stack_strdup(char *str)
{
    void        *ptr;
    t_stacks    *stack;

    ptr = ft_strdup(str);
    stack = ft_stack_init();
    stack->sys += ft_strlen(str) * sizeof(char);
    return (ptr);
}

static int      ft_alloc_size(void)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    int         size;
    
    stack = ft_stack_init();
    alloc = stack->alloc;
    size = 0;
    while (alloc)
    {
        size += ft_strlen(alloc->name) + ft_strlen(alloc->type);
        alloc = alloc->next;
    }
    return (size);
}

static void     ft_stack_display(void)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    
    stack = ft_stack_init();
    alloc = stack->alloc;
    while (alloc)
    {
        ft_putstr((char *)alloc->name);
        ft_putstr(" (");
        ft_putstr((char *)alloc->type);
        ft_putstr(") : ");
        if (alloc->content)
            ft_putendl((char *)alloc->content);
        alloc = alloc->next;
    }
}

void            ft_stack_infos(void)
{
    t_stacks    *stack;
    
    stack = ft_stack_init();
    ft_putendl("===========INFOS===========");
    ft_putstr("allocs               :");
    ft_putnbr_endl((int)stack->elements + (int)stack->free);
    ft_putstr("actifs               :");
    ft_putnbr_endl((int)stack->elements);
    ft_putstr("frees                :");
    ft_putnbr_endl(((int)stack->free));
    ft_putstr("bytes allocated      :");
    ft_putnbr_endl((int)stack->sys);
    ft_putendl("===========STACK===========");
    ft_stack_display();
    ft_putendl("===========STACK===========");
}

void            *ft_stack_clean(void)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    t_alloc     *next;
    
    stack = ft_stack_init();
    if (!stack)
        return (NULL);
    alloc = stack->alloc;
    while (alloc)
    {
        next = alloc->next;
        ft_alloc_delete(alloc);
        alloc = next;
    }
    stack->alloc = NULL;
    return (NULL);
}

void            *ft_stack_free(void)
{
    t_stacks    *stack;
    t_type      *type;
    t_type      *next;
    
    stack = ft_stack_init();
    if (!stack)
        return (NULL);
    ft_stack_clean();
    type = stack->types;
    while (type)
    {
        next = type->next;
        ft_vartype_delete(type);
        type = next;
    }
    ft_memdel((void**)&stack);
    return (NULL);
}

t_stacks            *ft_stack_init(void)
{
    static t_stacks *alloc;

    if (!alloc)
    {
        if (!(alloc = ft_memalloc(sizeof(t_stacks))))
            return (NULL);
        alloc->stack_size = 0;
        alloc->elements = 0;
        alloc->free = 0;
        alloc->sys = sizeof(t_stacks);
        alloc->alloc = NULL;
        alloc->types = ft_vartype_init();
    }
    return (alloc);
}

/* ************************************************************************** */

static void     *ft_alloc_delete(t_alloc *alloc)
{
    t_type      *type;
    t_stacks    *stack;
    int         size;

    stack = ft_stack_init();
    type = ft_vartype_get(alloc->type);
    stack->stack_size -= type->n_octet * alloc->size;
    type->del(&(alloc->content));
    stack->stack_size -= (ft_strlen(alloc->type) * sizeof(char));
    ft_strdel(&(alloc->type));
    ft_strdel(&(alloc->name));
    stack->elements -= 1;
    stack->free += 1;
    ft_memdel((void**)&(alloc));
    return (NULL);
}

void            *ft_alloc_pdel(void *content)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    t_alloc     *alloc_prev;
    t_alloc     *alloc_next;
    
    if (!(stack = ft_stack_init()) || !stack->alloc)
        return (NULL);    
    alloc = stack->alloc;
    alloc_next = alloc->next;
    alloc_prev = NULL;
    while (alloc)
    {
        alloc_next = alloc->next;
        if (alloc->content == content)
        {
            ft_alloc_delete(alloc);
            if (alloc_prev == NULL)
                stack->alloc = alloc_next;
            else
                alloc_prev->next = alloc_next;
        }
        alloc_prev = alloc;
        alloc = alloc_next;
    }
    return (NULL);
}

t_stacks        *ft_alloc_del(char *id)
{
    t_stacks    *stack;
    t_alloc     *alloc;
    t_alloc     *alloc_prev;
    t_alloc     *alloc_next;
    
    if (!(stack = ft_stack_init()) || !stack->alloc)
        return (NULL);    
    alloc = stack->alloc;
    alloc_next = alloc->next;
    alloc_prev = NULL;
    while (alloc)
    {
        alloc_next = alloc->next;
        if (!ft_strcmp(alloc->name, id))
        {
            ft_alloc_delete(alloc);
            if (alloc_prev == NULL)
                stack->alloc = alloc_next;
            else
                alloc_prev->next = alloc_next;
        }
        alloc_prev = alloc;
        alloc = alloc_next;
    }
    return (NULL);
}

void            *ft_alloc_vget(char *id)
{
    t_alloc     *alloc;

    alloc = ft_alloc_get(id);
    if (alloc && alloc->content)
        return (alloc->content);
    return (NULL);
}

t_alloc         *ft_alloc_get(char *id)
{
    t_stacks    *stack;
    t_alloc     *alloc;

    if (!(stack = ft_stack_init()))
        return (NULL);    
    alloc = stack->alloc;
    while (alloc)
    {
        if (ft_strcmp(alloc->name, id) == 0)
            return (alloc);
        alloc = alloc->next;
    }
    return (NULL);
}

static void     ft_alloc_more(char *type, t_stacks *stack, size_t len)
{
    t_type      *types;

    types = ft_vartype_get(type);
    stack->elements += 1;
    stack->stack_size += (len * types->n_octet);
}

void            *ft_alloc_copy(char *id, char *new)
{
    t_stacks    *stack;
    t_alloc     *alloc;

    stack = ft_stack_init();
    alloc = stack->alloc;
    while (alloc)
    {
        if (!ft_strcmp(alloc->name, id))
            return (ft_alloc(alloc->content, alloc->size, new, alloc->type));
        alloc = alloc->next;
    }
    return (NULL);
}

void            *ft_malloc(size_t len)
{
    t_alloc     *alloc;
    t_alloc     *new;
    t_stacks    *stack;

    if (!(stack = ft_stack_init()))
        return (NULL);    
    alloc = stack->alloc;
    while (alloc && alloc->next)
        alloc = alloc->next;
    if (!(new = ft_stack_memalloc(sizeof(t_alloc))))
        return (NULL);
    if (!(new->content = ft_stack_memalloc(len)))
        return (NULL);
    new->size = len;
    new->name = ft_stack_randomid();
    new->type = ft_stack_strdup("str");
    new->next = NULL;
    ft_alloc_more("str", stack, len);
    if (stack->alloc == NULL)
        stack->alloc = new;
    else
        alloc->next = new;
    return (new->content);
}

void            *ft_calloc(void *var, size_t len, char *id, char *type)
{
    t_alloc     *alloc;
    t_alloc     *new;
    t_stacks    *stack;

    if (!var || !(stack = ft_stack_init()) || !ft_vartype_get(type))
        return (NULL);    
    alloc = stack->alloc;
    while (alloc && alloc->next)
        alloc = alloc->next;
    if (!(new = ft_stack_memalloc(sizeof(t_alloc))))
        return (NULL);
    new->content = var;
    new->size = len;
    new->name = (id) ? ft_stack_strdup(id) : ft_stack_randomid();
    new->type = ft_stack_strdup(type);
    new->next = NULL;
    ft_alloc_more(type, stack, len);
    if (stack->alloc == NULL)
        stack->alloc = new;
    else
        alloc->next = new;
    return (new->content);
}

void            *ft_alloc(void *var, size_t len, char *id, char *type)
{
    t_alloc     *alloc;
    t_alloc     *new;
    t_stacks    *stack;

    if (!(stack = ft_stack_init()) || !ft_vartype_get(type))
        return (NULL);    
    alloc = stack->alloc;
    while (alloc && alloc->next)
        alloc = alloc->next;
    if (!(new = ft_stack_memalloc(sizeof(t_alloc))))
        return (NULL);
    if (!(new->content = ft_stack_memalloc(len)))
        return (NULL);
    if (var)
        new->content = ft_stack_memmove(new->content, var, len);
    new->size = len;
    new->name = (id) ? ft_stack_strdup(id) : ft_stack_randomid();
    new->type = ft_stack_strdup(type);
    new->next = NULL;
    ft_alloc_more(type, stack, len);
    if (stack->alloc == NULL)
        stack->alloc = new;
    else
        alloc->next = new;
    return (new->content);
}

/* ************************************************************************** */

t_type      *ft_vartype_init(void)
{
    t_type  *new;

    if (!(new = ft_stack_memalloc(sizeof(t_type))))
        return (NULL);
    new->type = ft_stack_strdup("str");
    new->n_octet = sizeof(char);
    new->del = ft_memdel;
    new->next = NULL;
    return (new);
}

t_type      *ft_vartype_get(char *type)
{
    t_stacks    *stack;
    t_type      *var;

    stack = ft_stack_init();
    var = stack->types;
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

t_type      *ft_vartype_add(char *type, size_t n, void (*del)(void**))
{
    t_type  *new;
    t_type  *node;
    t_stacks  *stack;

    stack = ft_stack_init();

    if (!type || !del || ft_vartype_get(type) != NULL)
        return (NULL);
    if (!(new = ft_stack_memalloc(sizeof(t_type))))
        return (NULL);
    if (!(new->type = ft_stack_strdup(type)))
        return (NULL);
    new->n_octet = n;
    new->del = del;
    new->next = NULL;
    if (!(node = stack->types->next))
        stack->types->next = new;
    else
    {
        while (node->next)
            node = node->next;
        node->next = new;
    }
    return (stack->types);
}

void        *ft_vartype_delete(t_type *var)
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
    return (NULL);
}

/* ************************************************************************** */

int     main(int argc, char **argv)
{
    t_stacks    *stack;
    char        *str;

    ft_alloc("coucou", 7, NULL, "str");
    ft_alloc(NULL, 4, "n2", "str");
    ft_alloc("u23", 4, NULL, "str");
    ft_alloc("42", 3, "nk", "str");
    ft_alloc_copy("nkc", "test");
    ft_stack_infos();
    DEL(n2);
    str = (char*)(GET(nk));
    PDEL(str);
    ft_stack_infos();
    ft_stack_clean();
    XSTR(test, nkc);
    ft_stack_infos();
    ft_stack_free();
    return (1);
}
