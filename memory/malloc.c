// 物理内存不足 2G
// 尝试申请 2G 内存
// 测试成功

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>

int main(){
	printf("申请 2G 内存\n");

  char *m1 = (char*)malloc(1024 * 1024 * 1024);
  for(int i = 0; i < 1024; i ++) 
    m1[i * 1024 * 1024] = 'a';

  sleep(10); 

  char *m2 = (char*)malloc(1024 * 1024 * 1024);
  for(int i = 0; i < 1024; i ++) 
    m2[i * 1024 * 1024] = 'b';

  sleep(60);

	printf("申请成功\n");

	return 0;
}
