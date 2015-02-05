/* ========================================
 * Points : 419.82
 * Total : 450
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class TranspositionKey {
public:
  vector <int> makeKey(string text) {
    string txt;
    for (auto & x : text) {
      if (isalpha(x)) {
        txt += toupper(x);
      }
    }

    int k=0;
    vector <int> result(txt.size());
    REP(c,26) {
      for (int i = 0; i < txt.size(); ++i) {
        if (txt[i]-'A' == c) {
          result[i] = ++k;
        }
      }
    }

    return result;
  }
};
