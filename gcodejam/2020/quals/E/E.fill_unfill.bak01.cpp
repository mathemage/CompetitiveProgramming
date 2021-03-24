/* ========================================
   * File Name : E.cpp
   * Creation Date : 19-03-2021
   * Last Modified : Tue 23 Mar 2021 11:56:22 PM CET
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209aa0
   * Points/Time :
   *  25m
   * +41m50s = 1h06m50s
   * +
   *
   * Total/ETA : 1h15m
   * Status :
   *
   ==========================================*/

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
  #define MSG_VEC(v) print_vector((v), (#v));
  #define MSG_VEC_PAIRS(v) print_vector_pairs((v), (#v));
  #define MSG_VEC_VEC(v) cerr << "> " << (#v) << ":\n" << (v) << endl;
  #define LINESEP1 cerr << "-----------------------------------------------                  " << endl;
  #define LINESEP2 cerr << "_________________________________________________________________" << endl;
#else
  #define MSG(a)
  #define MSG_VEC(v)
  #define MSG_VEC_PAIRS(v)
  #define MSG_VEC_VEC(v)
  #define LINESEP1
  #define LINESEP2
#endif

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

template<typename T>
void print_vector(const vector<T> & vec, const string & name) {
  cerr << "> " << name << ": ";
  cerr << vec;
  cerr << endl;
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
const int UNDEF = 0;
const long long MOD = 1000000007;

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


int n,k;

set<vector<int>> diags;
vector<int> prefix;
int prefixSum;

void genDiag(int nDigits, int lower=1) {
//   LINESEP1;
//   MSG(nDigits); MSG(lower);
//   MSG(prefix); MSG(prefixSum); MSG(diags);
  if (nDigits<=1) {
    int needed=k-prefixSum;
    if (prefixSum<k && lower<=needed && needed<=n) {
      prefix.PB(k-prefixSum);
      diags.insert(prefix);
      prefix.pop_back();
    }
  } else {
    FOR(digit,lower,n) {
      if (prefixSum+digit <= k) {
        prefixSum += digit;
        prefix.PB(digit);

        genDiag(nDigits-1, digit);

        prefixSum -= digit;
        prefix.pop_back();
      }
    }
  }
//   MSG(diags);
//   LINESEP1;
}

void fill(int row, int col, int digit, vector<vector<int>> & square, vector<vector<vector<bool>>> & avail) {
  if (square[row][col]==UNDEF) {
    square[row][col] = digit;
    REP(r,n) {
      avail[r][col][digit-1]=false;
    }
    REP(c,n) {
      avail[row][c][digit-1]=false;
    }
  }
}

void unfill(int row, int col, vector<vector<int>> & square, vector<vector<vector<bool>>> & avail) {
  int digit = square[row][col];
  if (digit!=UNDEF) {
    square[row][col]=UNDEF;
    REP(r,n) {
      avail[r][col][digit-1]=true;
    }
    REP(c,n) {
      avail[row][c][digit-1]=true;
    }
  }
}

void show_avail(const vector<vector<vector<bool>>> & avail) {
  cerr << "> avail: " << endl;
  REP(row,n) {
    REP(col,n) {
      REP(digit,n) {
        cerr << avail[row][col][digit];
      }
      cerr << " ";
    }
    cerr << endl;
  }
}

int rowCol;
bool dfs(vector<vector<int>> & square, vector<vector<vector<bool>>> & avail) {
  LINESEP1;

  // recursively (i.e. DFS) loop over row-col positions
  int row=rowCol/n, col=rowCol%n;
  while (row<n && col<n && square[row][col]!=UNDEF) {
    rowCol++;
    row=rowCol/n, col=rowCol%n;
  }
  MSG(row) MSG(col);

  if (rowCol>=n*n) {
    return true;
  }

  // loop over available digits
  FOR(digit,1,n) {
    // fill in -> make digit unavailable in its row and col
    if (avail[row][col][digit-1]) {
      fill(row, col, digit, square, avail);
#ifdef MATHEMAGE_DEBUG
      MSG_VEC_VEC(square); show_avail(avail);
#endif
      if (dfs(square, avail)) {
        return true;
      }
      unfill(row, col, square, avail);
    }
  }

  return false;
}

void solve() {
  cin >> n >> k;
  MSG(n); MSG(k);

  // generate diagonal with sum `k`
  LINESEP1;
  diags.clear(), prefix.clear(), prefixSum=0;
  genDiag(n);
  MSG(diags);
  LINESEP1;

  vector<vector<int>> square(n, vector<int>(n, UNDEF));

  vector<vector<vector<bool>>> avail(n,
    vector<vector<bool>>(n,
      vector<bool>(n, true)
    )
  );
#ifdef MATHEMAGE_DEBUG
  MSG_VEC_VEC(square);
//   LINESEP1;
//   fill(0,1,2,square,avail);
//   MSG_VEC_VEC(square);
  show_avail(avail);
// 
//   LINESEP1;
// 
//   fill(1,0,1,square,avail);
//   MSG_VEC_VEC(square);
//   show_avail(avail);
  LINESEP1;
#endif

  // loop over possible diags
  for (auto & diag: diags) {
    rowCol=0;

    REP(i,n) { fill(i, i, diag[i], square, avail); }
#ifdef MATHEMAGE_DEBUG
    MSG(diag);
    MSG_VEC_VEC(square); show_avail(avail);
#endif

    // run DFS to fill out the square
    bool possible = dfs(square, avail);
    if (possible) {
      cout << "POSSIBLE" << endl;
      cout << square << endl;
      return;
    }

    REP(i,n) { unfill(i, i, square, avail); }
#ifdef MATHEMAGE_DEBUG
    MSG_VEC_VEC(square); show_avail(avail);
    LINESEP1;
#endif
  }
  
  cout << "IMPOSSIBLE" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cases = 1;
  cin >> cases;
  REP(i,cases) {
    cout << "Case #" << i+1 << ": ";
    MSG(endl);
    solve();
    LINESEP2;
  }
  return 0;
}
