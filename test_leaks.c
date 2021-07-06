#include <stdlib.h>

char *test()
{
    char *q;
    q = (char *)malloc(1);
    return q;
}

void test2(char *q)
{
    
    free(q);

}


int main()
{
    char *q;
    char *temp;

    q = (char *)malloc(1);
    temp = q;
    q = (char *)malloc(1);
    free(temp);
    free(q);
}