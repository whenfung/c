#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

int    time_substract(struct timeval *result, struct timeval *begin,struct timeval *end)
{
    if(begin->tv_sec > end->tv_sec)    return -1;
    if((begin->tv_sec == end->tv_sec) && (begin->tv_usec > end->tv_usec))    return -2;
    result->tv_sec    = (end->tv_sec - begin->tv_sec);
    result->tv_usec    = (end->tv_usec - begin->tv_usec);

    if(result->tv_usec < 0)
    {
        result->tv_sec--;
        result->tv_usec += 1000000;
    }
    return 0;
}


int main(int argc, char** argv) {
    if(argc != 2) return -1;
    int n = atoi(argv[1]);
    struct timeval starttime,stop,diff;
    time_t start = time(NULL);
    gettimeofday(&starttime,0);    

    for(int i = 0; i < n; i ++) {
      int rc = fork();
      if (rc < 0) {
        fprintf(stderr, "fork failed\n");
      } else if (rc == 0) {
        return 0;
      } else {
        wait(NULL);
      }
    }
    gettimeofday(&stop,0);
    time_t end = time(NULL);
    time_substract(&diff,&starttime,&stop);
    printf("Total time : %d s,%d us\n",(int)diff.tv_sec,(int)diff.tv_usec);
    printf("多进程测试完成时间 : %ld 秒\n", end - start);
    return 0;
}
