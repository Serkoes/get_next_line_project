/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 23:20:17 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/09 23:08:59 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test6 - FAIL
// test from console with nothing - FAIL

#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include <stdio.h>
//#include "libft/libft.h"

void test_input()
{
    int fd;
    char *line;

    fd = 0;
    while ((line = get_next_line(fd)))   
    {                                      
        printf("%s", line);            
        free(line);                       
    }
}

void test(char  *name)
{
    int fd;
    char *line;
    char *file;
    
    printf("=-----------------%s-----------------\n",name);
    file = ft_strjoin("tests/", name);
    fd = open(file, O_RDONLY);
    line = NULL;
    while ((line = get_next_line(fd)))   
    {                                      
        printf("%s", line);            
        free(line);                       
    }                                      
    printf("%s", line);
    if (line)             
        free(line);
    free(file);
}

int main()
{
    // test("test1.txt");
    // test("qq");
    //test("test2.txt"); 
    // test("test3.txt"); 
    // test("test4.txt");
    // test("test5.txt");
    // test("test6.txt");
    // test("test7.txt");
    // test("alphabet.txt");
    // test("half_marge_top");
    //test("half_marge_bottom");
    //test("empty");
    //test("nl");
    //test_input();
    test("marge_test");
}
/*
files/empty: 1.OK 1.MKO 2.OK 2.MKO 
files/nl: 1.KO 1.MKO 2.OK 2.MOK 
files/41_no_nl: 1.OK 1.MOK 2.OK 2.MKO 
files/41_with_nl: 1.KO 1.MKO 2.OK 2.MOK 
files/42_no_nl: 1.OK 1.MOK 
files/42_with_nl: 1.KO 1.MKO 2.OK 2.MOK 3.OK 3.MKO
*/