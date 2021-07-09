/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:08:23 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/09 23:09:27 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void clean(char *target)
{
	size_t 	i;

	if (!target || !(*target))
		return ;
	i = 0;
	while (target[i])
		target[i++] = '\0';
	free(target);
}

char	*work_with_iter(char **line, char *iter)
{
	char				*find;
	unsigned int		count;

	find = ft_strchr(iter, '\n');
	if (!find)
	{
		*line = ft_strjoin(iter, "\0");
		clean(iter);
	}
	else
	{
		count = find - iter;
		*line = ft_substr(iter, 0, count);
		ft_strlcpy(iter, iter + count + 1);
	}
	return (iter);
}

char	*work_with_file(int fd, char *line, char **iter)
{
	int			count;
	char		buffer[BUFFER_SIZE+1];
	char		*find;
	char		*temp;

	count = read(fd, &buffer, BUFFER_SIZE);
	while (count)
	{
		buffer[count] = '\0';
		find = ft_strchr(buffer, '\n');
		if (find)
		{  
			buffer[find - buffer] = '\0';
			if (line)
			{
				temp = ft_strjoin(line, buffer);
				clean(line);
				line = temp;
			}
			else
				line = ft_strjoin(line, buffer);
			//buffer[find - buffer] = '\0';
			//leak на этом iter
			*iter = ft_strjoin(find + 1, "\0");
			if (!(*iter))
			{
				clean(line);
				line = NULL;
			}
			return (line);
		}
		temp = ft_strjoin(line, buffer);
		if (line)
			clean(line);
		line = temp;
		count = read(fd, &buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char			*iter = NULL;
	char				*line;
	char				*result;

	line = NULL;
	result = NULL;
	if ((read(fd, line, 0)) != 0)
		return (line);
	if (iter && *iter)
	{
		iter = work_with_iter(&line, iter);
		if (!line || !(*iter))
			return line;
	}
	line = work_with_file(fd, line, &iter);
	if (line)
		result = ft_strjoin(line,"\n");
		free(line);
		return (result);
	return (line);
}