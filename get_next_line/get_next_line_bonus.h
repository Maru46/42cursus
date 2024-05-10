/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:00:47 by klimrung          #+#    #+#             */
/*   Updated: 2024/05/10 15:11:40 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 14
# endif

# define OPENMAX 1024

typedef struct s_list
{
	char			*buff;
	size_t			byte;
	struct s_list	*next;
}			t_list;

typedef struct s_vars
{
	t_list	*head;
	t_list	*last;
	size_t	i;
	int		lastread;
}			t_vars;

char	*get_next_line(int fd);
t_list	*ft_lstnew(void);
void	ft_lstadd_back(t_vars *keep, t_list *new);
void	ft_lstdelone(t_list *new);
void	clearlist(t_vars *keep, int mode);
void	*ft_memset(void *s, int c, size_t n);

#endif