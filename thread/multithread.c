// 多线程测试速度

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int n;     // n 个进程

void* worker(void* arg) {
  printf("线程 %d 启动\n", *(int*)arg);
  float x = 1.0;
  for(float i = 0; i < 2520/n; i += 0.1) {  // n 个进程平坦任务
    for(float j = 0; j < 10000; j += 0.1) {
      x = x * 3.1415926 * 2;
      x = 1.0;
    }
  }

  printf("线程 %d 结束\n", *(int*)arg);
  return NULL;
}

int main(int argc, char* argv[]) {
  if (argc != 2) return 0;

  n = atoi(argv[1]);
  printf("%d 个线程在跑\n", n);
  
  if( n < 1 || n > 16) return 0;

  pthread_t t[16];  // 最多 10 个进程
  int arg[16];      // 10 个参数
  for(int i = 0; i < 16; i ++)
    arg[i] = i+1;
 
  time_t start = time(NULL);

  for(int i = 0; i < n; i++) {
    pthread_create(&t[i], NULL, worker, &arg[i]); 
  }

  for(int i = 0; i < n; i++) {
    pthread_join(t[i], NULL);
  }

  time_t end = time(NULL);

  printf("进程完成时间为 : %ld 秒\n", end - start);
    
  return 0;
}
