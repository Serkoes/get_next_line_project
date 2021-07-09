#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
# include <unistd.h>

int getter()
{
    return (4);
}

int main()
{
    int a=1;

    while ((a = getter()) > 0)
    {
       a++;
    }  
}