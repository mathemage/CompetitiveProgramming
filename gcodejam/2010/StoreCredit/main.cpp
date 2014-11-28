// https://code.google.com/codejam/contest/351101/dashboard#s=p0
#include <cstdio>
#include <vector>

//#define DEBUG
using namespace std;

int main()
{
  short N, C, I, P, j, k;
  vector<short> inStore(1001);

  scanf("%hd", &N);
  for (short i = 1; i <= N; i++) {
    inStore.assign(1000,0);
    scanf("%hd", &C);
    scanf("%hd", &I);
#ifdef DEBUG
    printf("N: %hd\t C: %hd\t I: %hd\n", N, C, I);
#endif

    bool caseClosed = false;
    for (j = 1; j <= I; j++) {
      scanf("%hd ", &P);
#ifdef DEBUG
      printf("j: %hd\t P: %hd\n", j, P);
#endif
      if (P < C) {
        if (!caseClosed && (k = inStore[C-P]) > 0) {
          printf("Case #%hd: %hd %hd\n", i, min(j, k), max(j, k));
          caseClosed = true;
        }
        inStore[P] = j;
      }
    }
  }

  return 0;
}

