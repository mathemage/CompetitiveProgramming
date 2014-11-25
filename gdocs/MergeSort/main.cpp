#include <iostream>
#include <cstdio>

using namespace std;

#define SZ 13

void showArray(int* arr, int start, int end) {
  while (start <= end) {
    printf("%d ", arr[start++]);
  }
}

void Merge(int* arr, int s1, int e1, int s2, int e2) {
  int* res = new int[e2-s2+e1-s1+2];
  int r = 0;
  int p1 = s1;
  int p2 = s2;

  while (p1 <= e1 && p2 <= e2) {
    if (arr[p1] < arr[p2]) res[r++] = arr[p1++];
    else res[r++] = arr[p2++];
  }

  while (p1 <= e1) res[r++] = arr[p1++];
  while (p2 <= e2) res[r++] = arr[p2++];
  while (--r >= 0)
    arr[s1+r] = res[r];      // r = 0 => arr[s1] = res[0]

  delete res;
}

// start, end indices inclusive
void MergeSort(int* arr, int start, int end) {
  if (start < end) {
    int middle = (end + start) / 2;

    printf("1: [%d %d]: ", start, middle);
    showArray(arr, start, middle);
    printf("\n");
    MergeSort(arr, start, middle);

    printf("2: [%d %d]: ", middle+1, end);
    showArray(arr, middle+1, end);
    printf("\n");
    MergeSort(arr, middle+1, end);

    showArray(arr, start, end);
    Merge(arr, start, middle, middle+1, end);
    printf(" -> ");
    showArray(arr, start, end);
    printf("\n");
    /*
    printf("\n[%d %d] [%d %d]:\n", start, middle, middle+1, end);
    for (int i = 0; i < SZ; i++) {
      printf("%d ", arr[i]);
    }
    */
  }
}


int main()
{
  //int a1[SZ] = {4,2,3};
  int a1[SZ] = {4,2,3,1,5,9,7,8,13,11,10,12,6};

  printf("Original array: ");
  for (int i = 0; i < SZ; i++) { printf("%d ", a1[i]); }
  printf("\n");

  MergeSort(a1, 0, SZ-1);
  printf("MergeSorted array: ");
  for (int i = 0; i < SZ; i++) { printf("%d ", a1[i]); }

  printf("\n");
  return 0;
}
