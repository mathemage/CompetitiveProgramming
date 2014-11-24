// http://www.careercup.com/question?id=6330205329162240

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int* sum(int* arr1, int len1, int* arr2, int len2) {
  if (len1 > len2) {
    swap(arr1, arr2);
    swap(len1, len2);
  }

  int *r = new int[len2 + 1];
  int carry = 0;
  for (int i = 0; i < len2; i++) {
    r[i] = ( (i < len1) ? arr1[i] : 0) + arr2[i] + carry;
    carry = r[i] / 10;
    r[i] %= 10;
  }
  r[len2] = carry;
  return r;
}

int len_of_sum(int len1, int len2) {
  return std::max(len1, len2) + 1;
}

int main()
{
  const int len1 = 3;
  int n1[len1] = {3,2,1};
  const int len2 = 2;
  int n2[len2] = {0,9};

  printf("len is %d\n", len_of_sum(3,2));

  int *res = sum(n1, 3, n2, 2);
  for (int i = 0; i < len1; i++) {
    printf("%d", n1[i]);
  }
  printf(" + ");
  for (int i = 0; i < len2;
       i++) {
    printf("%d", n2[i]);
  }
  printf(" == ");
  for (int i = 0; i < len_of_sum(3,2); i++) {
    printf("%d", res[i]);
  }
  printf("\n");
  delete res;
  return 0;
}
