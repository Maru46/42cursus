/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:49:52 by klimrung          #+#    #+#             */
/*   Updated: 2024/05/10 15:15:06 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new->buff)
	{
		free(new);
		return (NULL);
	}
	new->byte = 0;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_vars *keep, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (keep->head)
	{
		tmp = keep->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		keep->last = new;
	}
	else
	{
		keep->head = new;
		keep->last = keep->head;
	}
	return ;
}

void	ft_lstdelone(t_list *node)
{
	if (!node)
		return ;
	free(node->buff);
	free(node);
	node = NULL;
	return ;
}

void	clearlist(t_vars *keep, int mode)
{
	t_list	*tmp;

	if (!keep->head)
		return ;
	while (keep->head)
	{
		tmp = keep->head;
		keep->head = keep->head->next;
		if (keep->last == tmp)
			keep->last = NULL;
		ft_lstdelone(tmp);
		keep->i = 0;
		if (mode == 1)
			return ;
	}
	return ;
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
