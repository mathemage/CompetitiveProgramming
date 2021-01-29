#include <bits/stdc++.h>

#define fr first
#define sc second
#define be begin()
#define en end()
#define pb push_back

using namespace std;

typedef long long ll;

const int SIZE = 2 * 1e6 + 1, INF = 1e9;

inline void beg() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
bool used[SIZE];
int main() {
    beg();

    int t;
    cin >> t;

    while (t--){

        int n, k;
        cin >> n >> k;
        int l = 1, r = k;

        for (int i = 1; i <= k; ++i){
            if (i * n >= k && (((i*n) % k) + n - 1)/n < i){
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}

