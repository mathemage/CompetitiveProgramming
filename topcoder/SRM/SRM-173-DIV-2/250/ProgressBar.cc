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

class ProgressBar {
public:
  string showProgress(vector <int> taskTimes, int tasksCompleted) {
    int done = accumulate(taskTimes.begin(), taskTimes.begin() + tasksCompleted, 0);
    int all = accumulate(taskTimes.begin(), taskTimes.end(), 0);
    int perc = 20 * done / all;

    string res;
    REP(i,20) {
      res += (i < perc) ? '#' : '.';
    }
    return res;
  }
};

// 191.04/250
