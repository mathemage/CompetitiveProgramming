#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<P> VP;
typedef vector<V> VV;
typedef map<ll, ll> MP;
typedef multimap<ll, ll> MMP;
typedef set<ll> SET;
typedef multiset<ll> MSET;

#define loop(i,n) for(ll i = 0; i < n; i++)
#define loopr(i,x,y) for(ll i = x; i < y; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define deb(x) cout << #x << "=" << x << endl
#define endl '\n'
#define PI 3.1415926535897932384626
#define MOD 1000000007

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll test;

	cin >> test;

	while (test--) {

		ll n, k;

		cin >> n >> k;

		if (n > k) {

			ll tmp = k;

			while (k < n) {
				k += tmp;
			}
		}

		if (k % n == 0) {
			cout << (k / n) << endl;
		} else {
			ll val = k / n;

			val++;
			cout << val << endl;
		}
	}
}
