/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:08:23 by cchekov           #+#    #+#             */
/*   Updated: 2021/06/30 06:18:51 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*work_with_iter(char **line, char **strorage_iter, short int *status)
{
	char				*find;
	char				*iter;
	unsigned int		count;

	iter = *strorage_iter;
	find = NULL;
	*status = 1;
	find = ft_strchr(iter, '\n');
	if (!find)
	{
		*line = ft_strdup(iter, 0);
		free(iter);
	}
	else
	{
		count = find - iter;
		*line = ft_substr(iter, 0, count);
		ft_strlcpy(iter, iter + count + 1);
	}
	if (!line)
	{
		free(iter);
		*status = -1;
	}
	return (find);
}

short int	work_with_file(int fd, char **line, char **iter)
{
	int			count;
	char		buffer[BUFFER_SIZE+1];
	char		*find;
	char		*temp;

	while ((count = read(fd, &buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		if ((find = ft_strchr(buffer, '\n')))
		{
			temp = *line;
			buffer[find - buffer] = '\0';
			*line = ft_strjoin(*line, buffer);
			free(temp);
			*iter = ft_strdup(find + 1, count - (find - buffer) - 1);
			if (!*line || !*iter)
				return(-2);
			return (1);
		}
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		free(temp);
	}
	return (count);
}

int	get_next_line(int fd, char **line)
{
	char				*find;
	static char			*iter = NULL;
	short int			status;

	
	*line = '\0';
	//*line = ft_strdup("\0",1);
	if (iter)
	{
		find = work_with_iter(line, &iter, &status);
		if (status < 0)
			return (status);
		if (find)
			return (1);
		//else
		//	free(iter);
	}
	status = work_with_file(fd, line, &iter);
	if (status == 0 && iter && *iter)
		return (1);
	if (status == 0)
		iter = NULL;
	if (status == -1)
		free(*line);
	if (status < 0)
		return(-1);
    return (status);
}