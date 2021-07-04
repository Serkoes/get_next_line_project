/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:20:17 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/04 19:47:08 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test6 - FAIL
// test from console with nothing - FAIL

#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include <stdio.h>
//#include "libft/libft.h"

int main()
{
    int fd;
    char *line;
    
    //line = ft_strdup("1234",2);
    //printf("%s\n", line);
    
   /* fd = open("tests/alphabet.txt", O_RDONLY);
    printf("%d\n",BUFFER_SIZE);
    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line); 
        free(line);
    } 
    printf("%s\n",line);*/
    /*printf("%d\n",BUFFER_SIZE);
    fd = open("tests/half_marge_top", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);*/
    fd = open("tests/half_marge_bottom", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
    printf("%s", line);
	free(line);
    //free(line)  ; 
}