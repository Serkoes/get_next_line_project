#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
# include <unistd.h>

int test(char **t)
{
    *t = NULL;
    return (0);
}

int main()
{
    char    *line;
    ;
    test(&line);
    printf("dsada");
}