#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void* func(void* arg) {
  for(int i = 0; i < 5; i ++) {
    printf("func run %d\n", i);
    sleep(1);
  }
  return NULL;
}

int main() {
  pthread_t t;

  pthread_attr_t attr;      // 声明一个 attr 结构体
  pthread_attr_init(&attr); // 初始化结构体
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // 设置线程为分离线程

  int err = pthread_create(&t, &attr, func, NULL);
  if(err != 0) {
    printf("thread_create failed: %s\n", strerror(errno));
  } else {
    printf("thread_create success\n");
  }
  pthread_attr_destroy(&attr);
  
  pthread_join(t, NULL);
  printf("主线程退出\n");
  return 0;
}
