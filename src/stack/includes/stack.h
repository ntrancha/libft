/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:56:33 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/24 20:01:12 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"

# define    GET(variable)   ft_alloc_get(variable)
# define    VGET(variable)  ft_alloc_vget(#variable)
# define    DEL(variable)   ft_alloc_del(#variable)
# define    PDEL(variable) 	ft_alloc_pdel(variable)
# define    XSTR(vr, nm)    ft_alloc(#vr, ft_strlen(#vr) + 1, #nm, "str")
# define    ASTR(vr, nm)    ft_alloc(vr, ft_strlen(vr) + 1, nm, "str")
# define    CSTR(vr, nm)    ft_calloc(vr, ft_strlen(vr) + 1, nm, "str")
# define    DSTR(vr, nm)    ft_alloc_erase(vr, ft_strlen(vr) + 1, nm, "str")

typedef struct  s_alloc		t_alloc;
typedef struct  s_type		t_type;
typedef struct  s_stacks	t_stacks;
typedef struct  s_pile  	t_pile;
typedef struct  s_cnvrt     t_cnvrt;
typedef struct  s_funcs     t_funcs;
typedef union   u_func      t_func;

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
    int         (*len)(void*);
    void        *(*fus)(void*, void*, char*);
    int         (*count)(void*);
    int         (*cmp)(void*, void*);
    t_funcs     *func;
    t_type      *next;
};

struct          s_funcs
{
    char        *name;
    char        *func_name;
    t_func      *func;
    t_funcs     *next;
};

union           u_func
{
    void        *(*f_voidp_a)(void*);
    void        *(*f_voidp_b)(void*, void*);
    void        *(*f_voidp_c)(void*, void*, void*);
    void        (*f_void_a)(void*);
    void        (*f_void_b)(void*, void*);
    void        (*f_void_c)(void*, void*, void*);
    int         (*f_int_a)(void*);
    int         (*f_int_b)(void*, void*);
    int         (*f_int_c)(void*, void*, void*);
};

struct          s_cnvrt
{
    char        *src;
    char        *dst;
    void        (*cnvrt)(void*, char*);
    t_cnvrt     *next;

};

struct          s_pile
{
    char        *instruction;
    int         *line;
    t_pile      *next;
};

struct          s_stacks
{
    size_t      stack_size;
    size_t      stack_free;
    size_t      elements;
    size_t      sys;
    size_t      free;
    t_type      *types;
    t_pile      *pile;
    t_cnvrt     *convert;
    t_alloc     *alloc;
};

t_type          *ft_vartype_init(void);
t_type          *ft_vartype_add(char *type, size_t n, void (*del)(void**));
t_type          *ft_vartype_addput(char *type, void (*put)(void*));
t_type          *ft_vartype_addcpy(char *type, void *(*cpy)(void*,void*));
t_type          *ft_vartype_addcount(char *type, int (*count)(void*));
t_type          *ft_vartype_addlen(char *type, int (len)(void*));
t_type          *ft_vartype_addfus(char *type, void *(*fus)(void*, void*, char*));
t_type          *ft_vartype_addcmp(char *type, int (*cmp)(void*, void*));
t_type          *ft_vartype_get(char *type);
size_t          ft_vartype_getsize(char *type);
char            *ft_vartype_gettype(char *type);
void            *ft_vartype_delete(t_type *var);
t_stacks        *ft_stack_init(void);
void            *ft_stack_free(void);
void            *ft_stack_clean(void);
void            *ft_stack_memalloc(size_t size);
void            *ft_stack_memmove(void *dst, void *src, size_t len);
void            *ft_stack_strdup(char *str);
void            ft_stack_free_debug(void);
void            ft_stack_infos(void);
int             ft_stack_size(void);
void            *ft_malloc(size_t len);
void            *ft_calloc(void *var, size_t len, char *id, char *type);
void            *ft_calloc_erase(void *var, size_t len, char *id, char *type);
t_stacks        *ft_alloc_del(char *id);
t_stacks        *ft_alloc_rename(char *id, char *new_name);
t_cnvrt         *ft_alloc_cnvrt_add(char *s, char *d, void (*c)(void*, char*));
t_alloc         *ft_alloc_get(char *id);
t_alloc         *ft_alloc_getvoid(void *var);
void            *ft_alloc(void *var, size_t len, char *id, char *type);
void            *ft_alloc_include(void *var, size_t len);
void            *ft_alloc_nget(void *var);
void            *ft_alloc_vget(char *id);
void            *ft_alloc_copy(char *id, char *new);
void            *ft_alloc_pdel(void *content);
void            *ft_alloc_create(void *var, size_t len, char *id, char *type);
void            *ft_alloc_erase(void *var, size_t len, char *id, char *type);
void            *ft_alloc_fusion(char *one, char *two, char *new);
void            ft_alloc_cnvrt(char *src, char *type);
void            ft_alloc_put(char *id);
void            ft_alloc_convert(char *src, char *type_dst);
int             ft_alloc_cmp(char *a, char *b);
int             ft_alloc_cnvrt_xst(char *src, char *dst);
void            ft_stack_infos_func(void);
int             ft_vartype_func(char *str);
int             ft_alloc_len(char *a);
int             ft_alloc_count(char *a);

#endif
