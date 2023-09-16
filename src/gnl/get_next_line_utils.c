/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkshin <kkshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:47:27 by shikim            #+#    #+#             */
/*   Updated: 2023/04/20 03:39:06 by kkshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		++length;
	return (length);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*char_dst;
	char const	*char_src;

	char_dst = dst;
	char_src = src;
	if (char_dst == 0 && char_src == 0)
		return (0);
	if (char_dst < char_src)
	{
		while (len-- > 0)
			*char_dst++ = *char_src++;
	}
	else if (char_dst > char_src)
	{
		char_dst += len;
		char_src += len;
		while (len-- > 0)
			*--char_dst = *--char_src;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	char	*origin_joined_str;
	size_t	len_joined_str;

	len_joined_str = ft_strlen(s1) + ft_strlen(s2);
	joined_str = (char *)malloc(len_joined_str + 1);
	if (joined_str == NULL)
		return (NULL);
	origin_joined_str = joined_str;
	if (joined_str == 0)
		return (0);
	while (*s1 != '\0')
		*joined_str++ = *s1++;
	while (*s2 != '\0')
		*joined_str++ = *s2++;
	*joined_str = '\0';
	return (origin_joined_str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s) + 1;
	while (len_s-- > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(str) + 1;
	new_str = (char *)malloc(len);
	if (new_str == NULL)
		return (NULL);
	ft_memmove(new_str, str, len);
	return (new_str);
}
