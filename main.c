/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:20:17 by cchekov           #+#    #+#             */
/*   Updated: 2021/06/30 23:09:23 by cchekov          ###   ########.fr       */
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
    //int fd;
    char *line;
    
    //line = ft_strdup("1234",2);
    //printf("%s\n", line);
    //fd = open("tests/test7.txt", O_RDONLY);
    
    while (get_next_line(0, &line) > 0)
    {
        printf("%s\n", line); 
        free(line);
    } 
    printf("%s\n",line);
    //free(line)  ; 
}