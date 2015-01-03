/* ========================================

   ID: mathema6
   TASK: worder
   LANG: C++11
   (...for USACO solutions)

   * File Name : worder.cpp

   * Creation Date : 03-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemagegmail.com>

   * Problem :  Given an integer between 0 and 999,999, print an English phrase
   * that describes the integer (eg, "One Thousand, Two Hundred and Thirty
   * Four").Four

   ==========================================*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <cctype>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

string dozens[11] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
string ones[11] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
string teens[11] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string worder2(int k) {
	string res;
	if (k/100) res += ones[k/100] + " Hundred and ";
	k %= 100;

	if (k/10 == 1) return res + teens[k%10];
	if (k/10 > 1) res += dozens[k/10] + " ";
	res += ones[k%10];
  return res;
}

string worder(int n) {
	int m = n/1000;
	n %= 1000;

	string th;
	if (m)
		th += worder2(m) + " Thousand, ";

	return th + worder2(n);
}

int main() {
  cout << worder(1234) << endl;
  cout << worder(999999) << endl;
  cout << worder(109111) << endl;
  return 0;
}
