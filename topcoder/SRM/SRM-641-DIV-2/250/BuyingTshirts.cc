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


class BuyingTshirts {
public:
  int meet(int T, vector <int> Q, vector <int> P) {
    int res = 0;
    int N = Q.size();
    vector<bool> days(N);

    int sum = 0;
    REP(i,N) {
      sum += P[i];
      if (sum >= T) {
        MSG(i) MSG(sum)
        sum -= T;
        MSG(sum)
        days[i] = true;
      }
    }

    sum = 0;
    REP(i,N) {
      sum += Q[i];
      if (sum >= T) {
        sum -= T;
        res += days[i] == true;
      }
    }

    return res;
  }
};
