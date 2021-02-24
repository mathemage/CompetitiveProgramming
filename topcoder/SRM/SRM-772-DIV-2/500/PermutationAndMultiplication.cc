/* ========================================
 * Points/Time : 184.45 (1h 12m)
 * Total/ETA : 500 (13 m)
 * Status : AC !!!!!!!!!!!!!!!!!!
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
  cerr << name << " (reversed):\t";
//   for (const auto & x: vec) cerr << x << "  ";
  for (const auto & x: vec) cerr << x;
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
    int result=0;

    int n = ones-1;
//     int width=2*(ones+zeroes)+5;
    int width= n+zeroes + ones + 1;
    vector<int> l(width, 0);
    vector<int> s(width, 0);
    // 1 (0..0)xz (1..1)xn 
    REP(pos,n) {
      l[pos+ones]=1;
      s[pos]=1;
    }
    l[n+zeroes + ones]=1;
    s[n+zeroes]=1;
//     print_vector(l, "l");
//     print_vector(s, "s");

    // 1's complement of s
    REP(pos,width) {
      s[pos]=1-s[pos];
    }
    // 2's complement of s
    int carry=1;
    int sum;
    REP(pos,width) {
      sum=s[pos]+carry;
      s[pos]=sum%2;
      carry=sum/2;
    }
//     print_vector(s, "-s");

    // subtraction
    vector<int> d(width, 0);
    carry=0;
    REP(pos,width) {
//       if (!carry && !l[pos] && !s[pos]) {
//         break;
//       } 
// 
      sum=l[pos]+s[pos]+carry;
      result+=sum%2;
      d[pos]=sum%2;
      carry=sum/2;
//       MSG(pos) MSG(l[pos]) MSG(s[pos]) MSG(sum)
    }
//     print_vector(d, "d");

    return result;
  }
};
