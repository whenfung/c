#include <stdio.h>
#include <assert.h>

int main() {
  int t = 1;
  int f = -1;
  assert(t > 0);          // 断言为真, 继续执行
  printf("t = %d\n", t);  // 正常输出
  assert(f > 0);          // 断言为假, 结束进程
  printf("f = %d\n", f);  // 到不了这里 
  return 0;
}
