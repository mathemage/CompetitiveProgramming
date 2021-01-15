/* ========================================
 * Points : 248.25 (2nd fastest!)
 * Total : 250
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


class FriendFinder {
public:
  int distance(string line) {
    int result = 0;
    for (int i = 0; i < line.size(); i += 1) {
      if (line[i] == 'S') {
        result += i;
      }
      if (line[i] == 'F') {
        result -= i;
      }
    }
    return abs(result);
  }
};
