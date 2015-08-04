#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
    struct stat buf;

    if (stat("sl1",&buf) == -1)
    {
        perror("fail to stat");
        exit(1);
    }

    printf("**********sl1**********");
    printf("permission : %d\n",(int)buf.st_mode);
    printf("inode number : %d\n",(int)buf.st_ino);
    printf("device number : %d\n",(int)buf.st_dev);
    printf("r-device number : %d\n",(int)buf.st_rdev);
    printf("link : %d\n",(int)buf.st_nlink);
    printf("uid : %d\n",(int)buf.st_uid);
    printf("gid : %d\n",(int)buf.st_gid);
    printf("file size : %d\n",(int)buf.st_size);
    printf("access time : %d\n",(int)buf.st_atime);
    printf("modify time : %d\n",(int)buf.st_mtime);
    printf("change time : %d\n",(int)buf.st_ctime);
    printf("buf size : %d\n",(int)buf.st_blksize);
    printf("block size : %d\n",(int)buf.st_blocks);

    if (stat("test.txt",&buf) == -1)
    {
        perror("fail to stat");
        exit(1);
    }

    printf("**********test.txt**********");
    printf("permission : %d\n",(int)buf.st_mode);
    printf("inode number : %d\n",(int)buf.st_ino);
    printf("device number : %d\n",(int)buf.st_dev);
    printf("r-device number : %d\n",(int)buf.st_rdev);
    printf("link : %d\n",(int)buf.st_nlink);
    printf("uid : %d\n",(int)buf.st_uid);
    printf("gid : %d\n",(int)buf.st_gid);
    printf("file size : %d\n",(int)buf.st_size);
    printf("access time : %d\n",(int)buf.st_atime);
    printf("modify time : %d\n",(int)buf.st_mtime);
    printf("change time : %d\n",(int)buf.st_ctime);
    printf("buf size : %d\n",(int)buf.st_blksize);
    printf("block size : %d\n",(int)buf.st_blocks);

    return 0;
}