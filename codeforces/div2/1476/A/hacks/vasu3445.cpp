#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define MAX 1005
#define endl "\n"

//fast exponentiation
ll power(ll x, ll y, ll p = 1000000007)
{
  ll res = 1;
  x = x % p;
  if (x == 0)
    return 0;
  while (y > 0)
  {
    if (y & 1)
      res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

int main()
{
  fast
      ll tt;
  cin >> tt;
  while (tt--)
  {
    ll n,i,j,k;
    cin >> n >> k;
    if(k==n){
      cout << "1\n";
      continue;
    }
    if(k<n){
      ll org_k = k;
      ll var2 = n/k;
      k = k * (var2+1);      
      while(k-org_k>=n){
        k = k-org_k;
      }
    }
    // cout << "k: " << k << endl;  
    k-=n;
    ll var = k/n;
    // if(var==0){
    //   cout << "2\n";
    //   continue;
    // }
    ll rem = k - (n*var);
    if(rem!=0){
      cout << 1 + 1 + var << endl;
    }else{
      cout << 1 + var << endl;
    }
    // cout << 1 + max(var,rem) << endl;
  }
  return 0;
}
