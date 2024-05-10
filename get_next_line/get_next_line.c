/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:49:12 by klimrung          #+#    #+#             */
/*   Updated: 2024/05/10 15:18:26 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(t_vars *keep, size_t len)
{
	char	*line;
	size_t	i;

	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line[len] = '\0';
	i = 0;
	while (keep->head)
	{
		while (keep->head->buff[keep->i] != '\0')
		{
			line[i++] = keep->head->buff[(keep->i)++];
			if (keep->head->buff[(keep->i) - 1] == '\n')
			{
				if (keep->head->buff[keep->i] == '\0')
					clearlist(keep, 1);
				return (line);
			}
		}
		clearlist(keep, 1);
	}
	return (line);
}

static size_t	get_len(t_vars *keep)
{
	t_list	*tmp;
	size_t	len;
	size_t	i;

	if (!keep->head)
		return (0);
	len = 0;
	i = keep->i;
	tmp = keep->head;
	while (tmp && tmp->buff[i] != '\n')
	{
		len++;
		if (i == tmp->byte - 1)
		{
			tmp = tmp->next;
			i = 0;
		}
		else
			i++;
	}
	if (tmp && tmp->buff[i] == '\n')
		len++;
	return (len);
}

int	readtokeep(t_vars *keep, int fd)
{
	t_list	*new;
	int		readable;

	new = ft_lstnew();
	if (!new)
		return (-1);
	readable = read(fd, new->buff, BUFFER_SIZE);
	if (readable <= 0)
	{
		ft_lstdelone(new);
		if (readable == 0)
		{
			keep->lastread = 1;
			return (1);
		}
		else
			return (-1);
	}
	new->buff[readable] = '\0';
	new->byte = (size_t)readable;
	ft_lstadd_back(keep, new);
	return (1);
}

static int	has_nl(t_vars *keep)
{
	size_t	i;

	if (!keep->head)
		return (0);
	if (keep->head == keep->last)
		i = keep->i;
	else
		i = 0;
	while (keep->last->buff[i])
	{
		if (keep->last->buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_vars	keep[OPENMAX];
	char			*line;
	size_t			len;

	if (fd < 0 || fd >= OPENMAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!keep[fd].head)
		ft_memset(&keep[fd], 0, sizeof(t_vars));
	while (!has_nl(&keep[fd]) && keep[fd].lastread != 1)
	{
		if (readtokeep(&keep[fd], fd) == -1)
		{
			clearlist(&keep[fd], 0);
			return (NULL);
		}
	}
	len = get_len(&keep[fd]);
	if (len != 0)
		line = get_line(&keep[fd], len);
	if (len == 0 || !line)
	{
		clearlist(&keep[fd], 0);
		return (NULL);
	}
	return (line);
}
