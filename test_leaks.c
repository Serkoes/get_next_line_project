#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
# include <unistd.h>

int main()
{
    int i;
    char *temp;

    temp = "123";
    printf("%s\n",temp);
    i = read(1, temp, 0);
    printf("%s\n",temp);
    printf("%d\n",i);
}