/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:19:08 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/09 21:25:54 by cchekov          ###   ########.fr       */
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
	int		j;
	

	boof = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!boof)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		boof[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		boof[i++] = s2[j++];
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