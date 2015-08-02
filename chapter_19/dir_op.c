#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
    printf("create directory\n");

    if (mkdir("test_dir",S_IRUSR | S_IWUSR | S_IXUSR) == -1)
    {
        perror("fail to mkdir");
        exit(1);
    }

    printf("successfully make a dir\n");
    system("ls -l | grep test_dir");
    printf("\n");

    printf("delete directory\n");

    if (rmdir("test_dir") == -1)
    {
        perror("fail to mkdir");
        exit(1);
    }

    printf("successfully remove a dir\n");
    system("ls -l | grep test_dir");
    printf("\n");

    return 0;
    
}