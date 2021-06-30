
//#include "get_next_line/get_next_line.h"
#include <stdio.h>
# include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 30
#endif

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
		*line = ft_strdup(iter, 0);
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
	if (iter)
	{
		find = work_with_iter(line, &iter, &status);
		if (status < 0)
			return (status);
		if (find)
			return (1);
		else
			free(iter);
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

/* 
Нет тестов на ввод из командной строки
Нет тестов на пустую строку , неккоректные аргументы
Нет проверки на лики
*/

int main()
{
    int fd;
	int i;
    char *line;

	/*Keyboard Input
	printf("run test Keyboard\n\n");
	fd = 1;
	while (get_next_line(fd, &line) > 0)
		printf("--%s--\n", line);
	printf("--%s--\n", line);	

	/*File Tests
	printf("run test 1\n\n");
	fd = open("tests/test0.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("--%s--\n", line);
	printf("--%s--\n", line);	

	printf("run test 2\n\n");
	fd = open("tests/test2.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("--%s--\n", line);
	printf("--%s--\n", line);

	printf("run test 3\n\n");
	fd = open("tests/test3.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("--%s--\n", line);
	printf("--%s--\n", line);

	printf("run test 4\n\n");
	fd = open("tests/test4.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("--%s--\n", line);
	printf("--%s--\n", line);
	
	printf("run test 5\n\n");
	fd = open("tests/test5.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("--%s--\n", line);
	printf("--%s--\n", line);

	*/
	printf("run test 6\n\n");
	fd = open("tests/test6.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("--%s--\n", line);
	printf("--%s--\n", line);

	/*
	printf("run test 7\n\n");
	fd = open("tests/test7.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("--%s--\n", line);
	printf("--%s--\n", line);
	*/

}