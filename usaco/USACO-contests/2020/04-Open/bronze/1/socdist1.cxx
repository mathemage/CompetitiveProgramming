/* ========================================

   ID: mathema6
   TASK: socdist1
   LANG: C++14

   * File Name : socdist1.cxx
   * Creation Date : 30-03-2021
   * Last Modified : Wed 31 Mar 2021 12:46:05 AM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : http://usaco.org/index.php?page=viewproblem2&cpid=1035
   * Points/Time :
   *  1h20m :-/ :-/
   * +   6m20s = 1h26m20s
   * +  27m40s = 1h54m00s
   * +  11m50s = 2h05m50s
   * +  12m10s = 2h18m00s
   *
   * Total/ETA : 1h35m
   * Status :
   * 4/15 WA + 1/15 RE/MLE
   * 4/15 WA + 1/15 RE/MLE
   * 3/15 WA
   * 1/15 WA
   * 15/15 AC -> passed !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   *
   ==========================================*/

#include <algorithm>
#define PROBLEMNAME "socdist1"

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
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
#define SZ(x) ((int) (x).size())

#ifdef ONLINE_JUDGE
  #undef MATHEMAGE_DEBUG
#endif

#ifdef MATHEMAGE_DEBUG
  #define MSG(a) cerr << "> " << (#a) << ": " << (a) << endl;
  #define MSG_VEC_VEC(v) cerr << "> " << (#v) << ":\n" << (v) << endl;
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define LINESEP1
  #define LINESEP2
#endif

ostream& operator<<(ostream& os, const vector<string> & vec) {
  os << endl;
  for (const auto & s: vec) cerr << s << endl;
  return os;
}

template<typename T> 
ostream& operator<<(ostream& os, const vector<T> & vec) { 
  for (const auto & x: vec) os << x << " ";
  return os; 
} 

template<typename T> 
ostream& operator<<(ostream& os, const vector<vector<T>> & vec) { 
  for (const auto & v: vec) os << v << endl;
  return os; 
} 

template<typename T> 
ostream& operator<<(ostream& os, const set<T>& vec) { 
  os << "{ | ";
  for (const auto & x: vec) os << x << "| ";
  os << "}";
  return os; 
} 

template<typename T1, typename T2>
void print_vector_pairs(const vector<pair<T1, T2>> & vec, const string & name) {
  cerr << "> " << name << ": ";
  for (const auto & x: vec) cerr << "(" << x.F << ", " << x.S << ")\t";
  cerr << endl;
}

template<typename T>
inline bool bounded(const T & x, const T & u, const T & l=0) {
  return min(l,u)<=x && x<max(l,u);
}

const int CLEAN = -1;
const int UNDEF = -42;
const long long MOD = 1000000007;
const double EPS = 1e-8;

const int INF = INT_MAX;
const long long INF_LL = LLONG_MAX;
const long long INF_ULL = ULLONG_MAX;

const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};


#ifndef MATHEMAGE_LOCAL
void setIO(string filename) {    // the argument is the filename without the extension
	freopen((filename+".in").c_str(), "r", stdin);
	freopen((filename+".out").c_str(), "w", stdout);
  MSG(filename);
}
#endif

void solve() {
  int N;
  cin >> N;

  vector<int> gaps;
  int lastGap=0;

  char stall;
  REP(i,N) {
    cin >> stall;
    if (stall=='0') {
      lastGap++;
    } else {
      gaps.PB(lastGap);
      lastGap=0;
    }
  }
  gaps.PB(lastGap);
  MSG(gaps); MSG(gaps.size());

  if (gaps.size()==1) {
    cout << N-1 << endl;
    return;
  }

  vector<int> outer={gaps.front(), gaps.back()};
  gaps.erase(gaps.begin());
  gaps.pop_back();

  if (gaps.size()==0) {
    sort(REVALL(outer));

    int result=max(outer[1], outer[0]/2);
    cout << result << endl;
    return;
  }

  for (auto & gap: gaps) { gap++; }
  sort(REVALL(gaps));
  MSG(gaps); MSG(outer);

  int D=gaps.back();
  int result;
  MSG(D);

  int nPlacements=2;
  for (auto & o: outer) {
    while (nPlacements>0 && o>=D) {
      o-=D;
      nPlacements--;
    }
  }
  MSG(nPlacements);

  if (nPlacements==2) {
    result=min(D, gaps[0]/3);

//     if (gaps[0]>=2*D) {
//       MAXUPDATE(result, min(D, gaps[0]-2*D));
//     }

    if (gaps.size()>=2) {
      MAXUPDATE(result, min(D, gaps[1]/2));
    }
  } else if (nPlacements==1) {
    result = min(D, gaps[0]/2);
  } else {
    result=D;
  }

  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

#ifndef MATHEMAGE_LOCAL
  setIO(PROBLEMNAME);
#endif

  int cases = 1;
  while (cases--) {
    solve();
    LINESEP2;
  }
  return 0;
}
