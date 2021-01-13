/* ========================================
 * Points : 142.20
 * Total : 300
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;


class TapeMeasure {
public:
  vector <string> draw(int leftMark, int rightMark) {
    int rng = 1000;
//     int rng = 80;
    vector<string> full(5);
    REP(i,rng) {
      full[0] += "##";
      full[1] += "# ";
      full[2] += i % 5 ? "  " : "# ";
      full[3] += i % 10 ? "  " : "# ";
    }
    for (int i = 0; i < rng; i += 10) {
      string i_str = to_string(i);
      full[4] += i_str;
      REP(j,20-int(i_str.size())) {
        full[4] += " ";
      }
    }
    
    vector<string> result(5);
    REP(row,5) {
      result[row] = full[row].substr(2 * leftMark, 2 * (rightMark - leftMark) + 1);

//       cerr << full[row] << endl;
      cerr << result[row] << endl;
    }
    return result;
  }
};
