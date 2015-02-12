/* ========================================
 * Points : 258.34
 * Total : 300
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class OfficeParking {
public:
  int spacesUsed(vector <string> events) {
    int result=0, now = 0;
    string w1, w2;
    stringstream ss;
    for (auto & x : events) {
      ss.str(x);
      ss >> w1 >> w2;
      if (w2 == "arrives") now++;
      else now--;
      result = max(result, now);
      ss.clear();
      MSG(w1);
      MSG(w2);
      MSG(now);
    }

    return result;
  }
};
