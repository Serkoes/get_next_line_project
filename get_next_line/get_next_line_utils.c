/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:19:08 by cchekov           #+#    #+#             */
/*   Updated: 2021/06/30 05:47:29 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t	result;

	if (!s)
		return (0);
	result = 0;
	while (*(s)++ != '\0')
		result++;
	return (result);
}

char	*ft_strchr(const char *src, int c)
{
	if (c == '\0')
		return ((char *)(src + ft_strlen(src)));
	while (*src != '\0')
	{
		if (*src == c)
			return ((char *)src);
		src++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*boof;
	int		i;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	boof = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!boof)
		return (NULL);

	i = 0;
	if (s1_len)
	{
		while (*s1)
		{
			boof[i] = *s1;
			i++;
			s1++;
		}
	}
	if (s2_len)
	{
		while (*s2)
		{
			boof[i] = *s2;
			i++;
			s2++;
		}
	}
	boof[i] = '\0';
	return (boof);
}

size_t	ft_strlcpy(char *dest, char *src)
{
	unsigned int 	i;

	i = 0;
	while (src[i]){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*result;

	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	s = s + start;
	while (len--)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(char *src, size_t len)
{
	char	*dest;
	size_t	i;

	if (!len)
		len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}