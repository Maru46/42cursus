/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klimrung <klimrung@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:50:46 by klimrung          #+#    #+#             */
/*   Updated: 2024/02/27 16:58:26 by klimrung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	str_len;
	size_t	sub_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len <= start)
		return (ft_strdup(""));
	else if (str_len > start + len)
		sub_len = len + 1;
	else
		sub_len = str_len - start + 1;
	sub_str = (char *)malloc(sizeof(char) * (sub_len));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, sub_len);
	return (sub_str);
}
