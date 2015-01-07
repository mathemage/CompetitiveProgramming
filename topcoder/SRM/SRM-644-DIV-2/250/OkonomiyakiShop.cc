/* ========================================
 * Points : 249.99
 * Total : 250
 * Status : arena failed, ac on 1st attempt
 ==========================================*/

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
#include <string>
#include <cctype>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

// uncomment following line for debug mode
#define DEBUG

#ifdef DEBUG
#define MSG(a) cout << #a << " == " << a << endl;
#else
#define MSG(a) ;
#endif

class OkonomiyakiShop {
public:
  int count(vector <int> osize, int K) {
    int result = 0;

    //sort(ALL(osize));
    for (int i = 0; i <  osize.size(); ++i) {
      for (int j = i+1; j <  osize.size(); ++j) {
        result += (abs(osize[j] - osize[i]) <= K);
      }
    }
    return result;
  }
};
