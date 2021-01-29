#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define vec vector<int>
#define vecpair vector<pair<int,int>>
#define mp make_pair
#define fi first
#define se second

const int mod = 1e9 + 7;
vec v[10001], primes;
int vis[10001], dist[10001], maxdist, maxNode;

static ll power(ll x, ll y){
    //mod is prime number or the modular number
    ll res = 1;
    x = x%mod;
    if (x==0)
    return 0;
    while(y>0){
        if((y&1)==1)
        res = (res*x) % mod;
        
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

ll gcd(ll a, ll b){
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}

void dfs(int node){
    vis[node] = 1;
    for(int child : v[node]){
        if(!vis[child])
        dfs(child);
    }
}

ll nCr(int n, int r){
    ll fac[n+1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i-1] * i) % mod;
    return (fac[n]*power(fac[r], mod-2)%mod*power(fac[n-r],mod-2)%mod)%mod;
}

int main() {
	    int t;
	    cin>>t;
	    while(t--){
	        ll n,k;
	        cin>>n>>k;
	        ll f=0,c=1, p=k;
	        while(p<n){
	            c++;
	            p=k*c;
	        }
	        k*=c;
	        ll d = k%n;
	        if(d==0)
	        cout<<k/n<<endl;
	        else
	        cout<<1+k/n<<endl;
	    }
	return 0;
}
