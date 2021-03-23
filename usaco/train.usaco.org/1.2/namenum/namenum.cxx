/* ========================================

   ID: mathema6
   TASK: namenum
   LANG: C++11

   * File Name : namenumdict.cxx

   * Creation Date : 01-02-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://train.usaco.org/usacoprob2?a=CgCXoXRumyJ&S=namenum

   * Duration : 25 min

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

int main() {
  /*
   * 2: A,B,C     5: J,K,L    8: T,U,V
   * 3: D,E,F     6: M,N,O    9: W,X,Y
   * 4: G,H,I     7: P,R,S
   */
  const string keypad = "22233344455566670778889990";
  ifstream fin("namenum.in");
  ofstream fout("namenum.out");
  ifstream dict("dict.txt");
  string n, line, code;
  fin >> n;

  code = n;
  bool none = true;
  while (getline(dict, line)) {
    if (line.size() == n.size()) {
      REP(i,n.size()) code[i] = keypad[line[i]-'A'];
      if (code == n) {
        fout << line << endl;
        none = false;
      }
    }
  }
  if (none) fout << "NONE" << endl;
  return 0;
}
