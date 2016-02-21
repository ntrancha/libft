/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sysstr_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:10:58 by ntrancha          #+#    #+#             */
/*   Updated: 2016/02/21 21:10:39 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"
#include "../../includes/sys.h"
#include "../../includes/stack.h"
#include "../../includes/convert.h"
#define SRC_CONTENT     ((t_alloc*)src)->content
#define SRC_SIZE        ((t_alloc*)src)->size
#define SRC_NAME        ((t_alloc*)src)->name
#define SRC_TYPE        ((t_alloc*)src)->type

static void ft_sysstr_to_mem(void *src, char *dst)
{
    char    *old;
    char    *tmp;

    old = ft_strdup(SRC_NAME);
    if (src && ft_strcmp(dst, "mem") == 0)
    {
        tmp = ft_memalloc(SRC_SIZE - 1);
        ft_memcpy(tmp, (void*)SRC_CONTENT, SRC_SIZE - 1);
        ft_alloc_erase(tmp, SRC_SIZE - 1, old, dst);
    }
    if (src && ft_strcmp(dst, "str") == 0)
    {
        tmp = ft_memalloc(SRC_SIZE + 1);
        ft_memcpy(tmp, (void*)SRC_CONTENT, SRC_SIZE);
        tmp[SRC_SIZE] = '\0';
        ft_alloc_erase(tmp, SRC_SIZE + 1, old, dst);
    }
    ft_strdel(&old);
}

static void ft_sysint_to_mem(void *src, char *dst)
{
    char    *old;
    char    *tmp;

    old = ft_strdup(SRC_NAME);
    if (src && ft_strcmp(dst, "mem") == 0)
    {
        tmp = ft_memalloc(SRC_SIZE);
        ft_memcpy(tmp, (void*)SRC_CONTENT, SRC_SIZE);
        ft_alloc_erase(tmp, SRC_SIZE, old, dst);
    }
    if (src && ft_strcmp(dst, "int") == 0)
    {
        tmp = ft_memalloc(sizeof(int));
        if (sizeof(int) < SRC_SIZE)
            ft_memcpy(tmp, (void*)SRC_CONTENT, sizeof(int));
        else
            ft_memcpy(tmp, (void*)SRC_CONTENT, SRC_SIZE);
        ft_alloc_erase(tmp, sizeof(int), old, dst);
    }
    if (src && ft_strcmp(dst, "str") == 0)
    {
        tmp = ft_tabstrtostr((char**)SRC_CONTENT);
        ft_alloc_erase(tmp, ft_strlen(tmp) + 1, old, dst);
    }
    ft_strdel(&old);
}

static void ft_sysstr_to_int(void *src, char *dst)
{
    char    *old;
    char    *tmp;

    old = ft_strdup(SRC_NAME);
    if (src && ft_strcmp(dst, "int") == 0)
        ft_sysint_alloc(ft_atoi((char*)SRC_CONTENT), old);
    if (src && ft_strcmp(dst, "str") == 0)
    {
        tmp = ft_itoa((int)*((int*)SRC_CONTENT));
        ft_alloc_erase(tmp, ft_strlen(tmp) + 1, old, dst);
    }
    ft_strdel(&old);
}

static void ft_sysliststr_to_str(void *src, char *dst)
{
    char    *type;
    char    *old;
    char    *tmp;

    old = ft_strdup(SRC_NAME);
    if (src && ft_strcmp(dst, "str") == 0)
    {
        tmp = ft_listtostr((t_list*)SRC_CONTENT);
        ft_alloc_erase(tmp, ft_strlen(tmp) + 1, old, dst);
    }
    if (src && ft_strcmp(dst, "ft_opt") == 0)
    {
        type = ft_vartype_gettype("ft_opt");
        SRC_TYPE = type;
    }
    if (src && ft_strcmp(dst, "liststr") == 0)
    {
        type = ft_vartype_gettype("liststr");
        SRC_TYPE = type;
    }
    ft_strdel(&old);
}

void        ft_sysstr_convert(void)
{
    ft_alloc_cnvrt_add("str", "int", ft_sysstr_to_int);
    ft_alloc_cnvrt_add("int", "str", ft_sysstr_to_int);
    ft_alloc_cnvrt_add("str", "mem", ft_sysstr_to_mem);
    ft_alloc_cnvrt_add("mem", "str", ft_sysstr_to_mem);
    ft_alloc_cnvrt_add("int", "mem", ft_sysint_to_mem);
    ft_alloc_cnvrt_add("mem", "int", ft_sysint_to_mem);
    ft_alloc_cnvrt_add("tabstr", "str", ft_sysint_to_mem);
    ft_alloc_cnvrt_add("liststr", "str", ft_sysliststr_to_str);
    ft_alloc_cnvrt_add("ft_opt", "liststr", ft_sysliststr_to_str);
    ft_alloc_cnvrt_add("liststr", "ft_opt", ft_sysliststr_to_str);
}
