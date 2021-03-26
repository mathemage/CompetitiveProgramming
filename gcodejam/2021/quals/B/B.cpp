/* ========================================
   * File Name : B.cpp
   * Creation Date : 26-03-2021
   * Last Modified : Fri 26 Mar 2021 09:14:12 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
   * Points/Time :
   *  1h
   * +1h19m10s = 2h19m10s :-/
   *
   * Total/ETA : 5+11+1pts ~40m
   * Status :
   * AC (the 2 visible testsets)
   *
   ==========================================*/

#include <algorithm>
#include <bits/stdc++.h>
#include <string>

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
// const int UNDEF = -42;
const char UNDEF = '_';
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


void solve() {
  int x,y;
  string s;
  cin >> x >> y >> s;
  MSG(s);

  vector<string> options = {"CC", "JJ", "CJ", "JC"};

  map<string, int> cost;
  cost["CC"] = cost["JJ"] = 0;
  cost["CJ"] = x; cost["JC"] = y;

  map<string, char> prevChar;
//   for (auto & opt: options) prevChar[opt]=UNDEF;
  for (auto & opt: options) prevChar[opt]=opt[0];

  map<string, int> deltas;

  int n=s.size();

  int result = 0;
  int delta;
  string key;
  FOR(pos,1,n-1) {
    LINESEP1;
//     MSG(pos-1); MSG(pos);
    MSG(s.substr(pos-1));
    MSG(s[pos-1]); MSG(s[pos]);

    if (s[pos]=='?') {
      LINESEP1;
      MSG(prevChar["CC"]) MSG(prevChar["JJ"]) MSG(prevChar["CJ"]) MSG(prevChar["JC"]);
      if (s[pos-1]=='?') { // ??
        for (auto & opt: {"CJ", "JC"} ) {
          s[pos-1]=opt[0];
          s[pos]=opt[1];
          deltas[opt] += cost[s.substr(pos-1,2)];

          prevChar[opt]^='C'^'J';
        }
        s[pos-1]='?';
      } else {             // C? or J?
        for (auto & opt: options) {
          s[pos]=opt[0];
          deltas[opt] += cost[s.substr(pos-1,2)];

          prevChar[opt]=opt[0];
        }
      }
      s[pos]='?';
      LINESEP1;
      MSG(prevChar["CC"]) MSG(prevChar["JJ"]) MSG(prevChar["CJ"]) MSG(prevChar["JC"]);
      MSG(deltas["CC"]) MSG(deltas["JJ"]) MSG(deltas["CJ"]) MSG(deltas["JC"]);

      if (pos==n-1) {
        result+=min( min(deltas["CC"], deltas["JJ"]), min(deltas["CJ"], deltas["JC"]) );
      }
    } else {    // J or C
      if (s[pos-1]=='?') { // ?C or ?J
        MSG(prevChar["CC"]) MSG(prevChar["JJ"]) MSG(prevChar["CJ"]) MSG(prevChar["JC"]);
        for (auto & opt: options) {
          s[pos-1]=prevChar[opt];
          deltas[opt] += cost[s.substr(pos-1,2)];
        }
        delta=min( min(deltas["CC"], deltas["JJ"]), min(deltas["CJ"], deltas["JC"]) );

        MSG(deltas["CC"]) MSG(deltas["JJ"]) MSG(deltas["CJ"]) MSG(deltas["JC"])
        deltas["CC"]=deltas["JJ"]=deltas["CJ"]=deltas["JC"]=0;
        s[pos-1]='?';
      } else {
        delta=cost[s.substr(pos-1,2)];
      }

      MSG(delta);
      result += delta;
    }

    MSG(result);
  }
  
  cout << result << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cases = 1;
  cin >> cases;
  REP(i,cases) {
    cout << "Case #" << i+1 << ": ";
    solve();
    LINESEP2;
  }
  return 0;
}
