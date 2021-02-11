/* ========================================
 * Points :
 * Total : 1000
 * Status : unsubmitted
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
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 10e9+7;
const int LIM = 3005;


class SuperSubset {
public:
  int solve(vector <int> A, int Y) {
    vector<long long> pow2(LIM,1);
    FOR(exp,1,LIM) {
      pow2[exp] = (2 * pow2[exp-1]) % MOD;
//       MSG(exp); MSG(pow2[exp]);
    }

    sort(ALL(A));
    unordered_map<int,int> freq;
    for (auto & ai: A) {
      if (freq.count(ai) == 0) {
        freq[ai] = 0;
      }
      freq[ai]++;
    }
//     cerr << "freq: ";
//     for (auto & val: freq) {
//       cerr << val.F << " x" << val.S << "\t";
//     }
//     cerr << endl;

    long long result = 0LL;
    return result;
  }
};
