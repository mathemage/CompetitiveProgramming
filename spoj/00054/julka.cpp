/* ========================================

   * File Name : julka.cpp

   * Creation Date : 19-02-2015

   * Last Modified : Sun 22 Feb 2015 12:33:59 AM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

   * Points Gained (in case of online contest) :

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

void display(string s, string label) {
  cout << label << " == ";
  for (auto & x : s) {
    cout << int(x);
  }
  cout << endl;
}

string add(string a, string b) {
  if (a.size() > b.size()) {
    swap(a,b);
  }
  reverse(ALL(a));
  reverse(ALL(b));
  string res;
  char carry = 0;
  int m = max(a.size(),b.size());
  REP(i,m) {
    res += carry;
    if (i<a.size()) {
      res[i] += a[i];
    }
    if (i<b.size()) {
      res[i] += b[i];
    }
    carry = res[i] / 10;
    res[i] %= 10;
  }

  if (carry) {
    res += 1;
  }
  reverse(ALL(res));
  return res;
}

// only when a >= b
string subtract(string a, string b) {
  string c(a.size()-b.size(),9);
  for (auto & x : b) {
    c += 9-x;
  }
  string one(1,1);
  string res = add(add(a,c),one);
  int i = 1;
  for (auto & x : res.substr(1)) {
    if (x != 0) {
      return res.substr(i);
    }
    i++;
  }
  return res.substr(1,1);
}

string halve(string a) {
  string res;
  reverse(ALL(a));
  REP(i,a.size()) {
    res += (a[i]>>1);
    ERR(int(a[i]>>1));
    if (i < a.size()-1) {
      res[i] &= ((a[i+1]&0x1)<<4);
      ERR((a[i+1]&0x1)<<4)
    }
    ERR(i, int(a[i]), int(res[i]))
  }
  reverse(ALL(res));
  display(res,"half");
  int i = 0;
  for (auto & x : res) {
    if (x != 0) {
      return res.substr(i);
    }
    i++;
  }
  return res.substr(0,1);
}

int main() {
  string total, diff;
  REP(i,10) {
    cin >> total >> diff;
    ERR(total,diff);

    for (int i = 0; i < total.size(); ++i) {
      total[i] -= '0';
    }
    for (int i = 0; i < diff.size(); ++i) {
      diff[i] -= '0';
    }

    // t-d
    string res = subtract(total, diff);
    display(res, "t-d");
    string n = halve(res);
    string k = add(n,diff);
    display(k,"k");
    display(n,"n");
    cout << endl;

  }
  return 0;
}
