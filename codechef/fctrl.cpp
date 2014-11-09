#include<stdio.h>

typedef unsigned long ulong;

ulong z(ulong n) {
  ulong divisor = 5;
  ulong fives = 0;
  ulong inc;
  while( (inc = n / divisor) >= 1 ) {
    fives += inc;
    divisor *= 5;
  }
  return fives;
}

int main() {
  ulong t, n;
  scanf("%lu", &t);
  while (t-- > 0) {
    scanf("%lu", &n);
    printf("%lu\n", z(n));
  }
  return 0;
}
