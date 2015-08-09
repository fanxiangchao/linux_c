#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include "iolib.h"

#define MAX_LINE 1024
#define PORT 8000
#define NAME_LEN 256
#define ADDR_LEN 17

extern int init(struct sockaddr_in *sin,int *lfd,int sock_opt);

extern int do_get(int cfd,char *file,int size);

extern int do_put(int cfd,char *file);

extern int do_cd(int cfd,char *path);

extern int do_ls(int cfd,char *path);