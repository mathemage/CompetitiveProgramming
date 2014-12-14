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

class GreaterGameDiv2 {
public:
  int calc(vector <int> snuke, vector <int> sothe) {
    int result = 0;
    for (int i = 0; i <  snuke.size(); ++i) {
      result += snuke[i] > sothe[i];
    }

    return result;
  }
};

// 247.90 / 250 pts 
