/* ========================================
 * Points : 225.99
 * Total : 550
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class FourStrings {
public:
  int shortestLength(string a, string b, string c, string d) {
    string words[] = {a, b, c, d};
    int result = 0;
    for (auto & w : words) {
      result += w.size();
    }

    sort(words,words+4);
    do {
      //std::cout << words[0] << ' ' << words[1] << ' ' << words[2] << ' ' << words[3] << '\n';
      string superstr = words[0];
      FOR(i,1,4) {
        int n = superstr.size();
        REP(s,n) {
          string head = words[i].substr(0,n-s);
          string tail = superstr.substr(s,head.size());
          if (head.compare(tail) == 0) {
            superstr += words[i].substr(head.size());
            break;
          } else if (s == n-1) {
            superstr += words[i];
          }
        }
      }
      MSG(superstr);
      if (result > superstr.size()) {
        result = superstr.size();
      }
    } while ( std::next_permutation(words,words+4) );

    return result;
  }
};
