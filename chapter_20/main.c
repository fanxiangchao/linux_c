#include <time.h>
#include "common.h"

int main(int argc,char *argv[])
{
    char c1,c2;
    int interval;
    int duration;
    int intervation;
    int reportType = 0;
    char repTypeName[16];
    struct timeval now;
    reportType = STANDARD;

    strcpy(repTypeName,"Standard");

    if (argc > 1)
    {
        sscanf(argv[1],"%c%c",&c1,&c2);

        if (c1 != '-')
        {
            printf("wrong command\n");
            exit(1);
        }

        if (c2 == 's')
        {
            reportType = SHORT;
            strcpy(repTypeName,"Short");
        }else if (c2 == 'l')
        {
            reportType = LONG;
            strcpy(repTypeName,"Long");
            interval = atoi(argv[2]);
            duration = atoi(argv[3]);
        }
    }

    gettimeofday(&now,NULL);
    printf("Status report: %s\n at the time of : %s\n",repTypeName,(char *)ctime(&(now.tv_sec)));
    printf("the hostname is: ");
    search("/proc/sys/kernel/hostname","");

    switch(reportType)
    {
    case 0:
        search("/proc/cpuinfo","model name");
        search("/proc/version","");
        break;
    case 1:
        search("/proc/stat","cpu");
        search("/proc/stat","intr");
        search("/proc/stat","ctxt");
        search("/proc/stat","btime");
        search("/proc/stat","processes");
        break;
    case 2:
        search("/proc/meminfo","MemTotal");
        search("/proc/meminfo","MemFree");

        while(intervation < duration)
        {
            sleep(interval);
            if (get_load_avg() == -1)
            {
                exit(1);
            }

            intervation += interval;
        }
        break;
    default:
        printf("should not be here\n");
    }

    return 0;

}