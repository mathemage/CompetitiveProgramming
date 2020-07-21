 
/* ========================================

   * File Name : 15.2.cpp

   * Creation Date : 21-07-2020

   * Last Modified : Út 21. července 2020, 14:01:50

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/codingcompetitions/hacker-cup/2019/qualification-round/problems/B

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << (a) << endl;

const int CLEAN = -1;

template <typename T>
string NumberToString ( T Number ) {
  ostringstream ss;
  ss << Number;
  return ss.str();
}

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

bool get_result(string L) {
  int n_b = 0;
  int n_dot = 0;
  for (auto & c : L) {
    //MSG(c)
    if (c == 'B') {
      n_b++;
    }
    if (c == '.') {
      n_dot++;
    }
  }
  // MSG(n_b)
  // MSG(n_dot)
  // MSG(L.length())

  // Case of no '.'
  if (n_dot == 0) {
    return false;
  }

  // Case of enough 'B's for each '.'
  if (n_b >= n_dot) {
    return true;
  }

  // Case of enough >= 2 'B's - back and forth hopping until the end
  if (n_b >= 2) {
    return true;
  }

  // Otherwise false
  return false;
}

int main() {
  int T;
  cin >> T;

  string L;
  REP(i,T) {
    cin >> L;
    // MSG(L)

    string result = get_result(L) ? "Y" : "N";
    cout << "Case #" << i + 1 << ": " << result << endl;
  }

  return 0;
}
