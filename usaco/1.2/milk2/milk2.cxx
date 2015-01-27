/* ========================================

   ID: mathema6
   TASK: milk2
   LANG: C++11

   * File Name : milk2.cxx

   * Creation Date : 27-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://train.usaco.org/usacoprob2?a=HyIPb46irFd&S=milk2

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

int main() {
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");
  int n;
  fin >> n;
  vector<pair<int, int>> per(n);
  for (auto & x : per) {
    fin >> x.first >> x.second;
  }

  sort(ALL(per));
  int milk=0, nomilk=0, b=per[0].first, e=per[0].second;
  for (auto & x : per) {
    if (x.first <= e) {
      e = max(e, x.second);
      milk = max(milk, e-b);
    } else {
      b = x.first;
      nomilk = max(nomilk, b-e);
      e = x.second;
    }
  }
  fout << milk << " " << nomilk << endl;

  return 0;
}
