#include<stdio.h>

int reverse(int num) {
  int reversed = 0;
  while (0 == num % 10) {
    num /= 10;
  }

  while (num > 0) {
    reversed *= 10;
    reversed += num % 10;
    num /= 10;
  }

  return reversed;
}

void process() {
  int num1, num2;
  scanf("%d %d\n", &num1, &num2);
  printf("%d\n", reverse(reverse(num1)+reverse(num2)));
}

int main() {
  int count;
  scanf("%d\n", &count);

  for (count; count > 0; count--) {
    process();
  }
  return 0;
}
