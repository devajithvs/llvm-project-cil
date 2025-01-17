// RUN: %cml %s -o %t && %t | FileCheck %s
#include <stdio.h>

int main() {
  int a;
  a = 3;
  int c = 10;
  int b = 10;

  do {
    a = a + 1;
    b = b + 10;
    c = c + 11;
    if (a > 7) {
      do {
        b = b + 10;
      } while (b < 100);
    }
  } while (a < 10);

  printf("%d %d %d\n", a, b, c);
  return 0;
}
// CHECK: 10 140 87
