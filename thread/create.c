#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

// 使用 man pthread_create 查看说明

void* func(void* arg) {
  printf("func run...\n");
  return NULL;
}

int main() {
  pthread_t t;
  int err = pthread_create(&t, NULL, func, NULL);
  if(err != 0) {
    printf("thread_create failed: %s\n", strerror(errno));
  } else {
    printf("thread_create success\n");
  }
  sleep(1);
  return 0;
}
