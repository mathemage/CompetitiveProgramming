#include <cstdio>

using namespace std;

void InsertionSort(int *arr, int len) {
  for (int i = 1; i < len; i++) {
    int curValue = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > curValue) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = curValue;
  }
}

int main()
{
  int arr[5] = {4,2,3,1,5};
  InsertionSort(arr, 5);
  for (int x : arr) {
    printf("%d\n", x);
  }
  return 0;
}

