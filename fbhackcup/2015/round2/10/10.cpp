/* ========================================

   ID: mathema6
   TASK: 10
   LANG: C++11
   (...for USACO solutions)

   * File Name : 10.cpp

   * Creation Date : 24-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/hackercup/problems.php?pid=193964420699886&round=323882677799153

   * Points Gained (in case of online contest) : 10 -> got a T-shirt :D

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

#define ERR(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

int t,n;

int main() {
  cin >> t;
  REP(i,t) {
    printf("Case #%d: ", i+1);
    cin >> n;
    vector<int> perm(n);
    REP(j,n) cin >> perm[j];
    int head, tail;

    int b=0, t=n-1;
    head = tail = perm[b++];
    bool ok = true;
    while (b <= t) {
      if (perm[b] == head + 1) {
        head = perm[b++];
      } else if (perm[b] == tail - 1) {
        tail = perm[b++];
      } else if (perm[t] == head + 1) {
        head = perm[t--];
      } else if (perm[t] == tail - 1) {
        tail = perm[t--];
      } else {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "yes\n";
      continue;
    }

    b=0, t=n-1;
    head = tail = perm[t--];
    ok = true;
    while (b <= t) {
      if (perm[b] == head + 1) {
        head = perm[b++];
      } else if (perm[b] == tail - 1) {
        tail = perm[b++];
      } else if (perm[t] == head + 1) {
        head = perm[t--];
      } else if (perm[t] == tail - 1) {
        tail = perm[t--];
      } else {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "yes\n";
      continue;
    }

    cout << "no\n";
  }
  return 0;
}
