#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class ShufflingCardsDiv2 {
public:
  string shuffle(vector <int> permutation) {
    string res = "";
    int N = permutation.size() / 2;
    int a, b, c, d;
    a = b = c = d = 0;

    REP(i,2*N) {
      MSG(i)
      if (!(i%2)) {
        MSG(!(i%2))
          cout << " versus " << endl;
        MSG(!i%2)
        if (permutation[i] <= N) a++;
        else b++;
      } else {
        MSG(i%2)
        if (permutation[i] > N) d++;
        else c++;
      }
    }
    cout << endl;

    MSG(a)
    MSG(b)
    MSG(c)
    MSG(d)

    int n1 = N / 2;
    int n2 = (N+1) / 2;
    MSG(n1)
    MSG(n2)
    return (a == n2 && b == n1 && c == n1 && d == n2) ? "Possible" : "Impossible";
  }
};
