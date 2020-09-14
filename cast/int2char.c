#include <stdio.h>

int
main() {
  int mode = 0x200 | 0x002 | 0x001;
  char flag = (char)mode;
  printf("mode: %x\n", mode);
  printf("flag: %x\n", flag);
  return 0;
}
