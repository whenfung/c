#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void* func(void* arg) {
  while(1) {
    printf("fun run...\n");
    sleep(1);
  }
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
  sleep(5);
  pthread_cancel(t);
  pthread_join(t, NULL);
  return 0;
}
