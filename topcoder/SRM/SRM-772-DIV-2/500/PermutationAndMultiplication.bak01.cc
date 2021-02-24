/* ========================================
 * Points/Time :
 * Total/ETA : 500 (13 m)
 * Status :
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MTP make_tuple
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define CONTAINS(S,E) ((S).find(E) != (S).end())

#define MSG(a) cerr << "> " << #a << ": " << (a) << endl;
template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << name << ": ";
  for (const auto & x: vec) cerr << x << "  ";
  cerr << endl;
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

// direction vectors - 4 directions
const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
// direction vectors - 8 directions
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};


class PermutationAndMultiplication {
public:
  int multiplyAndCount(int ones, int zeroes) {
    if (ones == 1) {
      return 1;
    }

    int n = ones-1;
    vector<int> prod(3*(ones+zeroes), 0);
    int result=0;

    // (1..1)x(n-1) (0..0)xn 1
    prod[0]=1;
    result++;
    FOR(pos,n+1,2*n-1) {
      prod[pos]=1;
      result++;
    }

    int carry=0;
    int sum;
    FOR(pos,n+1,n+n) {
      sum=prod[pos]+1+carry;
      result += sum%2 - prod[pos];
      carry=sum/2;
    }
    result += carry%2 - prod[n+n+1];

    // TODO
    carry=0;
    FOR(pos,n+1,n+n) {
      sum=prod[pos]+1+carry;
      result += sum%2 - prod[pos];
      carry=sum/2;
    }
    result += carry%2 - prod[n+n+1];

    return result;
  }
};
