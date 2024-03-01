/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:55:46 by klimrung          #+#    #+#             */
/*   Updated: 2024/02/29 16:03:02 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list	*test = ft_lstnew("4");
	t_list	*a, *b, *c;

	a = ft_lstnew("3");
	b = ft_lstnew("2");
	c = ft_lstnew("1");

	ft_lstadd_front(&test, a);
	ft_lstadd_front(&test, b);
	ft_lstadd_front(&test, c);
	printf("%s\n", (char *)ft_lstlast(test)->content);

	t_list	*temp = test;

	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}

	while (test)
	{
		t_list *next_node = test->next;
		free(test);
		test = next_node;
	}
	test = NULL;
	return (0);
}
*/