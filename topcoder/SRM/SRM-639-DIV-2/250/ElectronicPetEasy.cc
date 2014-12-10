
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

using namespace std;

// }}}

class ElectronicPetEasy
{
public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
	{
    vector<bool> times(1001 + 1000*1000);
    for (int i = 0; i < t1; i++) {
      times[st1 + i*p1] = true;
    }

    for (int i = 0; i < t2; i++) {
      if (times[st2 + i*p2]) {
        //MSG(i) MSG(st2) MSG(p2) MSG(t2)
        return "Difficult";
      }
    }

		return "Easy";
	}
};

