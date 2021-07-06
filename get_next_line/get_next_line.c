/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:08:23 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/04 19:54:50 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void clean(char *target)
{
	size_t i;
	char	**obj;


	obj = &target;
	i = 0;
	//printf("TEST CLEAN\n");
	//printf("target = %p | obj = %p \n", target, obj);
	while (target[i])
	{
		target[i] = '\0';
		i++;
	}
	//printf("target = %p | obj = %p \n", target, obj);
	free(target);
	*obj = NULL;
	//printf("target = %p | obj = %p \n", target, obj);
}

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
		//printf("free line  | LINE - %p\n", *line);
		clean(*line);
		*line = ft_strdup(iter, 0);
		//printf("alloc line| LINE - %p\n", *line);
	}
	else
	{
		count = find - iter;
		//printf("free line\n");
		clean(*line);
		//printf("alloc line\n");
		*line = ft_substr(iter, 0, count);
		ft_strlcpy(iter, iter + count + 1);
	}
	if (!(*line))
	{
		printf("free iter\n");
		clean(iter);
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
			//printf("alloc line in WWF \\n | LINE - %p\n", *line);

			//printf("free line in WWF \\n | LINE - %p\n", temp);
			clean(temp);
			
			*iter = ft_strdup(find + 1, count - (find - buffer) - 1);
			//printf("alloc iter in WWF \\n | ITER - %p\n", *iter);
			if (!*line || !*iter)
				return(-2);
			return (1);
		}
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		//printf("alloc line in WWF | LINE - %p\n", *line);
		//printf("free line in WWF | LINE - %p\n", temp);
		clean(temp);
	}
	return (count);
}

int	get_next_line(int fd, char **line)
{
	char				*find;
	static char			*iter = NULL;
	short int			status;

	
	//*line = "\0";
	*line = ft_strdup("\0",1);
	//printf("alloc line in GNL FIRST | LINE - %p \n", *line);
	if (iter)
	{
		find = work_with_iter(line, &iter, &status);
		if (status < 0)
			return (status);
		if (find)
			return (1);
		else
		{
			//clean(iter);
			//printf("free iter in GNL 120  | ITER - %p \n", iter);
					
		}
	}
	
	status = work_with_file(fd, line, &iter);
	if (status == 0 && iter && *iter)
		return (1);
	if (status == 0)
	{
		//printf("null iter in 128");
		iter = NULL;
	}

	if (status < 0)
		return(-1);
    return (status);
}