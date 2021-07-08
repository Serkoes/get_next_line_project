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

void test(char  *name)
{
    int fd;
    int result;
    char *line;
    char *file;

    printf("=-----------------%s-----------------\n",name); 
   // fd = open(ft_strjoin(folder, name), O_RDONLY);
    file = ft_strjoin("tests/", name);
    fd = open(file, O_RDONLY);
    //printf("%d\n",BUFFER_SIZE);            
    while ((result = get_next_line(fd, &line)) > 0)   
    {                                      
        printf("%d\n%s\n", result, line);
        printf("SYMBOL - %d\n", *line);
        //printf("free line in main\n");             
        free(line);                       
    }                                      
    printf("%d\n%s\n", result, line);
    printf("SYMBOL - %d\n", *line);
    //printf("free line in end\n");                  
    free(line); 
    free(file);
}

int main()
{
    // test("test1.txt");
    // test("test2.txt");
    // test("test3.txt");
    // test("test4.txt");
    // test("test5.txt");
    // test("test6.txt");
    // test("test7.txt");
    // test("alphabet.txt");
    // test("half_marge_top");
    // test("half_marge_bottom");
    // test("empty");
    test("nl");
}

/*
files/empty: 1.OK 1.MKO 2.OK 2.MKO 
files/nl: 1.KO 1.MKO 2.OK 2.MOK 
files/41_no_nl: 1.OK 1.MOK 2.OK 2.MKO 
files/41_with_nl: 1.KO 1.MKO 2.OK 2.MOK 
files/42_no_nl: 1.OK 1.MOK 
files/42_with_nl: 1.KO 1.MKO 2.OK 2.MOK 3.OK 3.MKO
*/