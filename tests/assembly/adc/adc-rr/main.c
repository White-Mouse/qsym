#include "common.h"
#include <unistd.h>

int main() {
  int a, b, v;
  read(0, &a, sizeof(a));
  read(0, &b, sizeof(b));

  __asm__("add $0x01234567, %1\n"
      "mov $0xabcdef, %%eax\n"
      "adc %%eax, %2\n"
      "mov %2, %0\n"
      : "=m"(v)
      : "r"(a), "r"(b)
      : "eax");

  if (v == 0xdeadbeef)
    good();
  else
    bad();
}
