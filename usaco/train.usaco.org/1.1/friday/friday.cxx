 
/* ========================================

   ID: mathema6
   TASK: friday
   LANG: C++14

   * File Name : friday.cxx
   * Creation Date : 05-04-2021
   * Last Modified : Út 6. dubna 2021, 00:15:20
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://train.usaco.org/usacoprob2?a=z0LKoxIejUN&S=friday
   * Points/Time :
   *   3m
   * +30m10s = 33m10s :-(
   *           <- bug in logic: `month==2` instead of `month==1`
   * + 4m10s = 37m20s
   *           <- annoying issues with no extra space and missing endl (not modern OJ)
   *
   * Total/ETA : 13m
   * Status :
   * Execution error (extra space)
   * AC
   *
   ==========================================*/

#define PROBLEMNAME "friday"

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

using ll = long long;
using ul = unsigned long long;
using llll = pair<ll, ll>;
using ulul = pair<ul, ul>;

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

vector<string> daysInWeek{"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};

void solve() {
  int N;
  cin >> N;

  vector<int> daysInMonths{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int dayOf13th = 0; // Mon Jan 15, 1900 => Sat Jan 13, 1900

  vector<int> result(7); // Sat, Sun, Mon, ..., Fri (==6)
  FOR(year,1900,1900+N-1) {
    FOR(month,0,11) {
      LINESEP1;
      MSG(year); MSG(month); MSG(month+1);
      MSG(dayOf13th); MSG(daysInWeek[dayOf13th]);

      result[dayOf13th]++;

      dayOf13th += daysInMonths[month]%7;
      if (month==1 && ((year%4==0 && year%100!=0) || year==2000)) {
        dayOf13th++;
      }
      dayOf13th %= 7;
    }
  }

  REP(d,7) {
    cout << result[d] << (d==6?endl:" ");
  }
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
