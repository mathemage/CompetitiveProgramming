/* ========================================
 * Points : 165.54
 * Total : 500
 * Status : WA WA AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Quacking {
public:
  int quack(string s) {
    int result = 0;
    for (auto & c : s) {
      switch (c) {
        case 'q': c = '0'; break;
        case 'u': c = '1'; break;
        case 'a': c = '2'; break;
        case 'c': c = '3'; break;
        case 'k': c = '4'; break;
      }
    }

    vector<int> st(5);
    for (auto & c : s) {
      int n = c - '0';
      int pred = (n + 4) % 5;
      MSG(c); MSG(n); MSG(pred);
      if (st[pred] > 0) {
        st[pred]--;
      } else {
        if (n == 0) {
          result++;
        } else {
          return -1;
        }
      }
      st[n]++;
      MSG(result); cout << endl;
    }

    REP(k,4) {
      if (k < 4 && st[k] > 0) {
        return -1;
      }
    }
    return result;
  }
};
