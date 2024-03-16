/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:09:35 by klimrung          #+#    #+#             */
/*   Updated: 2024/02/22 14:54:05 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cut_word(char const *s, char c, size_t *start)
{
	size_t	begin;
	char	*word;

	while (s[*start] == c && s[*start])
		(*start)++;
	begin = *start;
	while (s[*start] != c && s[*start])
		(*start)++;
	word = ft_substr(s, begin, *start - begin);
	return (word);
}

static int	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_check(char **res, size_t index)
{
	if (!res || !res[index])
	{
		while (index > 0)
		{
			index--;
			free(res[index]);
		}
		free(res);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	index;
	size_t	i;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res[index] = ft_cut_word(s, c, &i);
			if (ft_check(res, index))
				return (NULL);
			index++;
		}
		else
			i++;
	}
	res[index] = NULL;
	return (res);
}
