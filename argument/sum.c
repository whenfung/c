// 不确定参数传递，... 符

#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...) 
{
  va_list valist;
  va_start(valist, num);  // 为 num 个参数初始化 valist

  int sum = 0;
  for(int i = 0; i < num; i ++)
    sum += va_arg(valist, int);   // 逐个访问参数
  va_end(valist);   // 清理为 valist 保留的内存
  return sum;
}

int main() {
  printf("1 + 2 = %d\n", sum(2, 1, 2));
  printf("1 + 2 + 3 = %d\n", sum(3, 1, 2, 3));
  return 0;
}
