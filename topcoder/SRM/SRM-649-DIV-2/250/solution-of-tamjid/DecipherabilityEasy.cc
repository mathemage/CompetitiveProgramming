/* ========================================
 * Points : 202.74
 * Total : 250
 * Status : unsuccesfully challenged
 *    <- string::size() is of unsigned type, abs() of their difference is pointless, so it always is >1 :-(
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class DecipherabilityEasy {
public:
  string check(string s, string t) {
    int diff = 0;
    MSG(s.size()) MSG(t.size())
    MSG(s.size()-t.size())
    MSG(abs(s.size()-t.size()))

    int n = s.size();
    int m = t.size();
    if (abs(n-m)>1 || s.size()==t.size()) return "Impossible";
    for (int i=0;i<min(s.size(),t.size());i++)
      if (s[i]!=t[i])
      {
        if (s.size()<t.size())
        {
          s.insert(i,"#");
        }
        else
        {
          t.insert(i,"#");
        }
        diff++;
      }
    cout << s << " " << t << endl;
    cout << diff << endl;
    if (diff>1) return "Impossible";
    return "Possible";
  }
};
