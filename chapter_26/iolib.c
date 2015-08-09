#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t my_read(int fd,void *buffer,size_t length)
{
    ssize_t done = length;

    while(done > 0)
    {
        done = read(fd,buffer,length);

        if (done == -1)
        {
            if (errno == EINTR)
            {
                done = length;
            }
            else
            {
                perror("fail to read");
                return -1;
            }
        }
        else
        {
            break;
        }
    }

    return done;
}

ssize_t my_write(int fd,void *buffer,size_t length)
{
    ssize_t done = length;

    while(done > 0)
    {
        done = write(fd,buffer,length);

        if (done != length)
        {
            if (errno == EINTR)
            {
                done = length;
            }else
            {
                perror("fail to write");
                return -1;
            }
        }else
        {
            break;
        }
    }

    return done;
}