 
/* ========================================
   * File Name : upvotes_via_dp.cpp
   * Creation Date : 04-02-2021
   * Last Modified : Pá 5. února 2021, 00:24:55
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://www.hackerrank.com/contests/quora-haqathon/challenges/upvotes/problem
   * Points/Time : 1h 2m - ? - +9m 50s
   * Total/ETA : 1h 15m
   * Status : WA (10/29) & TLE (3/29 when debug print) - WA (10/29) - WA (9/29)
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
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
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

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


void print_vector(vector<long long> vec, string name) {
  cerr << name << ": ";
  for (auto & x: vec) {
    cerr << x << "  ";
  }
  cerr << endl;
}

void print_queue(queue<long long> q, string name) {
  cerr << name << ": ";
	while (!q.empty()){
		cerr << q.front() << "  ";
		q.pop();
	}
	cerr << endl;
}

void solve() {
  int N,K;
  cin >> N >> K;
  vector<int> upvotes(N);
  REP(i,N) {
    cin >> upvotes[i];
  }

  vector<long long> counts_inc(N,0LL);
  vector<long long> counts_dec(N,0LL);
  queue<long long> lengths_inc, lengths_dec;
  lengths_inc.push(0LL), lengths_dec.push(0LL); // because of `upvotes[0]`
  FOR(i,1,N) {
    if (upvotes[i-1]<=upvotes[i]) {
      counts_inc[i] = counts_inc[i-1]+1;
      lengths_inc.back()++;
    } else {
      lengths_inc.push(0LL);
    }

    if (upvotes[i-1]>=upvotes[i]) {
      counts_dec[i] = counts_dec[i-1]+1;
      lengths_dec.back()++;
    } else {
      lengths_dec.push(0LL);
    }
  }

  /* DEBUG */
  print_vector(counts_inc, "counts_inc");
  print_vector(counts_dec, "counts_dec");
  print_queue(lengths_inc, "lengths_inc");
  print_queue(lengths_dec, "lengths_dec");
  /*********/

  /* initial 1st window */
  int win_start=0, win_end=win_start+K-1;
  long long balance = 0LL;
  FO(win_pos,win_start,win_end) {
    balance += counts_inc[win_pos] - counts_dec[win_pos];
//       MSG(win_pos); MSG(counts_inc[win_pos]); MSG(counts_dec[win_pos]); MSG(balance);
  }
  cout << balance << endl;
  /**********************/

  for (win_start=1, win_end=win_start+K-1 ; win_end < N; win_start++, win_end++) {
//       cerr << endl; MSG(win_start); MSG(win_end); MSG(balance);
    balance += counts_inc[win_end] - counts_dec[win_end];
//       MSG(balance);

    if (lengths_inc.front()==0) {
      lengths_inc.pop();
    } else {
      balance -= min((long long)K, lengths_inc.front());
      lengths_inc.front()--;
    }
//       MSG(balance);

    if (lengths_dec.front()==0) {
      lengths_dec.pop();
    } else {
      balance -= -min((long long)K, lengths_dec.front());
      lengths_dec.front()--;
    }
//       MSG(balance);
    cout << (K==1?0:balance) << endl;
  }
}

int main() {
  int cases;
  cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
