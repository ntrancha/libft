/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shugueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:32:31 by shugueno          #+#    #+#             */
/*   Updated: 2014/11/06 10:48:03 by shugueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "tests.h"

void	test_lstnew(t_list *list, char *s1, size_t size)
{
	list = ft_lstnew(s1, size);
	while (list)
	{
		if (!strcmp(list->content, s1))
			printf("\033[32mOK cmp, ");
		else
			printf("\033[31mFATAL ERROR : %s != %s", s1, list->content);
		if (list->content_size == size)
			printf("OK size, ");
		else
			printf("\033[31mFATAL ERROR : %lu != %lu", size, list->content_size);
		if (list->next == NULL)
			printf("Ok next is null !\n");
		list = list->next;
	}
}

void	f(t_list *list)
{
	printf("%s %lu\n", list->content, list->content_size);
}

t_list	*f2(t_list *elem)
{
	elem->content_size = 13;
	elem->content = "Replace by 42";
	return (elem);
}

void	del(void *content, size_t size)
{
	free (content);
}

void	try_ft_lstdelone(void)
{
	printf("\n\n\033[0m******Test ft_lstdelone******\n\n");	
	t_list *list;
	t_list **ap;
	ap = (t_list **)malloc(sizeof(t_list *));
	char *s1 = ft_strdup("Bonjour");
	list = ft_lstnew(s1, 8);	
	t_list	*new;
	new = ft_lstnew(ft_strdup("3eme maillon"), 3);
	ft_lstadd(&list, new);
	ap = &list;
	ft_lstdelone(ap, del);
}

void	try_ft_lstdel(void)
{
	printf("\n\n\033[0m******Test ft_lstdel******\n\n");	
	t_list *list;
	t_list **ap;
	ap = (t_list **)malloc(sizeof(t_list *));
	list = ft_lstnew(ft_strdup("Bonjour"), 8);	
	t_list	*new;
	new = ft_lstnew(ft_strdup("3eme maillon"), 3);
	ft_lstadd(&list, new);
	ap = &list;
	ft_lstdel(ap, del);
}

void	try_ft_lstnew(void)
{
	printf("\n\n\033[0m******Test ft_lstnew******\n\n");	
	t_list	*list;
	test_lstnew(list, "Bonjour", 8);	
	test_lstnew(list, "", 1);
	test_lstnew(list, "Hello", 5);
}

void	try_ft_lstadd(void)
{
	printf("\n\n\033[0m******Test ft_lstadd******\n");	
	printf("\033[31mCheck if no use of malloc in source code !!\n\n");	
	t_list	*list;
	t_list	*new;
	list = ft_lstnew("\033[33m3eme maillon", 18);	
	new = ft_lstnew("\033[33m2eme maillon", 18);
	ft_lstadd(&list, new);
	new = ft_lstnew("\033[33m1er maillon", 17);
	ft_lstadd(&list, new);	
	new = NULL;
	ft_lstadd(&list, new);
	while (list)
	{
		printf("%s %lu\n", list->content, list->content_size);
		list = list->next;
	}
}

void	try_ft_lstiter(void)
{
	printf("\n\n\033[0m******Test ft_lstiter******\n\n");	
	t_list	*list;
	t_list	*new;
	list = ft_lstnew("\033[33m3eme maillon", 18);	
	new = ft_lstnew("\033[33m2eme maillon", 18);
	ft_lstadd(&list, new);
	new = ft_lstnew("\033[33m1er maillon", 17);
	ft_lstadd(&list, new);
	ft_lstiter(list, f);
}

void	try_ft_lstmap(void)
{
	printf("\n\n\033[0m******Test ft_lstmap******\n\n");	
	t_list	*list;
	t_list	*new;
	t_list *new2;
	list = ft_lstnew("3eme maillon", 13);	
	new = ft_lstnew("2eme maillon", 13);
	ft_lstadd(&list, new);
	new2 = ft_lstnew("1er maillon ", 13);
	ft_lstadd(&list, new2);
	t_list *renew;
	renew = ft_lstmap(list, f2);
	ft_lstiter(renew, f);
}



int main(void)
{
	try_ft_lstnew();
	try_ft_lstdelone();
	try_ft_lstdelone();
	try_ft_lstadd();
	try_ft_lstiter();
	try_ft_lstmap();
	return (0);
}
