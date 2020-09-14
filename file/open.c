#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int 
main() {
  // 1. 创建文件并写入内容
  // open 的参数分别是: 文件名, 模式, 权限
  int fd = open("temp", O_WRONLY | O_CREAT, 777); // 创建文件
  char s[] = "open test.";
  char buffer[80];
  write(fd, s, sizeof(s));  // 写数据
  close(fd);

  // 2. 读出内容
  fd = open("temp", O_RDONLY);
  read(fd, buffer, sizeof(buffer)); // 读数据
  close(fd);

  // 3. 输出内容
  printf("%s\n", buffer);
  return 0;
}
