#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vvi             vector<vi>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define inf             1e18
#define deb(x)          cout << #x << "=" << x << '\n';
#define ps(x,y)         fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const char ln='\n';
const char sp=' ';
const int mod=1000000007;
int modpow(int x, int y, int p);
int modinv(int a, int m);
int lcm(int a, int b);
int gcd(int a, int b);
bool po2 (int x);
struct comp;

void solve() {
    int n, k;
    cin>>n>>k;
    int r, cur=1;
    while(1)
    {
        if((cur*n)%k==0 || ((cur*n)>k && cur!=1))
        {
            break;
        }
        else
        {
            cur++;
        }
    }
    cout<<cur<<ln;
}

int32_t main() {
    FIO;
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool po2(int x) {
    return x && (!(x&(x-1)));
}

int modpow(int x, int y, int p) {
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modinv(int a, int m) {
    int g = gcd(a, m);
    if (g != 1)
        return -1;
    else {
        return modpow(a, m - 2, m);
    }
}

struct comp {
    bool operator()(pii const& p1, pii const& p2) {
        if(p1.first>p2.first) return true;
        else if(p1.first<p2.first) return false;
        else return p1.second>p2.second;
    }
};

