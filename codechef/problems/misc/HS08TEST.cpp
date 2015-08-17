#include<iostream>
#include<iomanip>
using namespace std;

int main() {
  int withdraw;
  double balance;

  cin >> withdraw >> balance;
  double new_balance = balance - withdraw - 0.5;
  cout << setprecision(2) << fixed
       << ( (0 == withdraw % 5 && new_balance >= 0) ? new_balance : balance )
       << endl;
}
