#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main(int argc,char *argv[])
{
    FILE *fp;
    char buf[MAX];
    int n;
    char *p;
    int letter,number,blank;

    fp = fopen("test.txt","rb");
    if (fp == NULL)
    {
        perror("fail to open");
        exit(1);
    }

    letter = 0;
    number = 0;
    blank = 0;

    while ((n = fread(buf,sizeof(char),MAX - 1,fp)) > 0)
    {

        buf[n] = '\0';
        p = buf;

        while(*p != '\0')
        {
            if (('a' <= *p && *p <= 'z') || ('A' <= *p && *p <= 'Z'))
            {
                letter++;
            }

            if (*p == ' ')
            {
                blank++;
            }

            if ('0' <= *p && *p <= '9')
            {
                number++;
            }

            p++;
        }
    }

    if (n == -1)
    {
        perror("fail to open");
        exit(1);
    }

    printf("the sum of letter is : %d\nthe sum of num is : %d\nthe sum of blank is : %d\n",
           letter,number,blank);
    return 0;
}