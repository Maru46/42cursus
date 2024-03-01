/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:03:00 by klimrung          #+#    #+#             */
/*   Updated: 2024/02/28 09:09:25 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	node_count;
	t_list	*temp;

	node_count = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		node_count++;
	}
	return (node_count);
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
	t_list	*test;
	t_list	*a, *b, *c;

	a = ft_lstnew("10");
	b = ft_lstnew("20");
	c = ft_lstnew("30");
	test = NULL;

	ft_lstadd_front(&test, c);
	ft_lstadd_front(&test, b);
	ft_lstadd_front(&test, a);
	printf("%d\n", ft_lstsize(test));

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