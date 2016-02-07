/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/07 01:44:33 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"
# define  GET(variable) 	ft_alloc_vget(#variable)
# define  DEL(variable)     ft_alloc_del(#variable)
# define  PDEL(variable) 	ft_alloc_pdel(variable)
# define  XSTR(var, name) 	ft_alloc(#var, ft_strlen(#var) + 1, #name, "str")

typedef struct  s_alloc		t_alloc;
typedef struct  s_type		t_type;
typedef struct  s_stacks	t_stacks;

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
    void        (*put)(void*);
    void        *(*cpy)(void*, void*);
    t_type      *next;
};

struct  s_stacks
{
    size_t      stack_size;
    size_t      stack_free;
    size_t      elements;
    size_t      sys;
    size_t      free;
    t_type      *types;
    t_alloc     *alloc;
};

t_type          *ft_vartype_init(void);
t_type          *ft_vartype_add(char *type, size_t n, void (*del)(void**));
t_type          *ft_vartype_addput(char *type, void (*put)(void*));
t_type          *ft_vartype_addcpy(char *type, void *(*cpy)(void*,void*));
t_type          *ft_vartype_get(char *type);
char            *ft_vartype_gettype(char *type);
void            *ft_vartype_delete(t_type *var);
void            *ft_stack_free(void);
void            ft_stack_infos(void);
void            *ft_stack_clean(void);
void            *ft_stack_free(void);
void            *ft_stack_memalloc(size_t size);
void            *ft_stack_memmove(void *dst, void *src, size_t len);
void            *ft_stack_strdup(char *str);
int             ft_stack_size(void);
void            *ft_malloc(size_t len);
void            *ft_calloc(void *var, size_t len, char *id, char *type);
void            *ft_alloc(void *var, size_t len, char *id, char *type);
void            *ft_alloc_include(void *var, size_t len);
t_alloc         *ft_alloc_get(char *id);
t_alloc         *ft_alloc_getvoid(void *var);
void            *ft_alloc_nget(void *var);
void            *ft_alloc_vget(char *id);
void            *ft_alloc_copy(char *id, char *new);
void            *ft_alloc_pdel(void *content);
t_stacks        *ft_stack_init(void);
t_stacks        *ft_alloc_del(char *id);
t_stacks        *ft_alloc_rename(char *id, char *new_name);

#endif
