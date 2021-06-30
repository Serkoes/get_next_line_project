/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:11:00 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/01 00:26:12 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# include <unistd.h>
# include <stdlib.h>
# include "stdio.h"
# include <fcntl.h>

int	    	get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *src, int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dest, char *src);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strdup(char *src, size_t len);
char		*work_with_iter(char **line, char **strorage_iter, short int *status);
short int	work_with_file(int fd, char **line, char **iter);
#endif
