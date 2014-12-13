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

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef long long ll;

class NumberGameAgain {
public:
  long long solve(int k, vector<long long> table) {
    ll result = (1LL<<k) -2;
    //ll result = pow(2,k)-2;
    sort(table.begin(), table.end());

    int sz = table.size();
    vector<bool> invalid(sz, false);
    vector<int> width(sz);

    for (int i = 0; i < sz; i++) {
      ll t = table[i];
      while (t) {
        t >>= 1;
        width[i]++;
      }	
    }

    for (int i = 0; i < sz-1; i++) {
      if (invalid[i])
        continue;
      for (int j = i+1; j < sz; j++) {
        int shift = width[j]-width[i];
        if ( table[i] == (table[j] >> shift) ) {
          invalid[j] = true;
        }
      }
    }

    for (int i = 0; i < sz; i++) {
      if (!invalid[i]) {
        result -= (1LL<<k-width[i]+1) - 1;
      }
    }

    return result;
  }
};
