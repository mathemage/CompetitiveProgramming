#include<stdio.h>
#include<stdint.h>
using namespace std;

typedef unsigned int dword;
int main() {
  dword n, k, val;
  dword count = 0;
  scanf("%u %u", &n, &k);
  for (dword i = 0; i < n; i++) {
    scanf("%u", &val);
    if (0 == val % k) {
      count++;
    }
  }
  printf("%u\n", count);
}
