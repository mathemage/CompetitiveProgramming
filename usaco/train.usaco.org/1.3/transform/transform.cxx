/* ========================================

   ID: mathema6
   TASK: transform
   LANG: C++11

   * File Name : transform.cxx

   * Creation Date : 30-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://train.usaco.org/usacoprob2?a=GinO3tPLU0G&S=transform

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
  cout << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << endl;
  err(++it, args...);
}

int n;

vector<string> rotate(const vector<string> & sq) {
  int k = 0;
  vector<string> res(n, string(n,' '));
  REP(j,n) FOR(i,n,0) {
    res[k/n][k%n] = sq[i][j];
    k++;
  }
  return res;
}

vector<string> reflect(const vector<string> & sq) {
  vector<string> res = sq;
  for (auto & x : res) {
    reverse(ALL(x));
  }
  return res;
}

int main() {
  ifstream fin("transform.in");
  ofstream fout("transform.out");
  fin >> n;
  vector<string> before(n);
  vector<string> after(n);
  REP(i,n) fin >> before[i];
  REP(i,n) fin >> after[i];

  vector<string> tmp = before;
  int res = 7;
  if ((tmp = rotate(tmp)) == after) res = 1;
  else if ((tmp = rotate(tmp)) == after) res = 2;
  else if ((tmp = rotate(tmp)) == after) res = 3;
  else if ((tmp = reflect(before)) == after) res = 4;
  else if ((tmp = rotate(tmp)) == after) res = 5;
  else if ((tmp = rotate(tmp)) == after) res = 5;
  else if ((tmp = rotate(tmp)) == after) res = 5;
  else if (before == after) res = 6;

  fout << res << endl;
  return 0;
}
