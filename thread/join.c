#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// 使用 man pthread_join 查看说明

void* func(void* arg) {
  for(int i = 0; i < 5; i ++) {
    printf("func run %d\n", i);
    sleep(1);
  }
  int *p = (int*)malloc(sizeof(int));
  *p = 11;
  return p;
}

int main() {
  pthread_t t;
  int err = pthread_create(&t, NULL, func, NULL);
  if(err != 0) {
    printf("thread_create failed: %s\n", strerror(errno));
  } else {
    printf("thread_create success\n");
  }
  void *p = NULL;
  pthread_join(t, &p);
  printf("线程退出: code = %d\n", *(int*)p);
  return 0;
}
