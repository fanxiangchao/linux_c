#include <stdio.h>

int add(int a,int b)
{
    return a + b;
}
int main(int argc,char *argv[])
{
    int a = 1;
    int b = 2;
    int c = add(a, b);
    printf("sum of %d and %d is %d",a,b,c);
}