#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
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


void* worker(void* arg) {
  return arg;
}

int main(int argc, char** argv) {
  if(argc != 2) return -1;
  int n = atoi(argv[1]);

  struct timeval starttime,stop,diff;
  time_t start = time(NULL);

  gettimeofday(&starttime,0);
  pthread_t t;
  for(int i = 0; i < n; i++) {
    pthread_create(&t, NULL, worker, NULL); 
    pthread_join(t, NULL);
  }
  gettimeofday(&stop,0);
  time_t end = time(NULL);

  printf("进程完成时间为 : %ld 秒\n", end - start);
  time_substract(&diff,&starttime,&stop);
  printf("Total time : %d s,%d us\n",(int)diff.tv_sec,(int)diff.tv_usec);
  
  return 0;
}
