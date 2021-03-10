#include <bits/stdc++.h>
using namespace std;
const int N = 100020;

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

int T, n, k, a[N];

int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	
	T = read();
	while (T--) {
		n = read(), k = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + n + 1);
		if (k == 0) { cout << n << endl; continue; }
		int mex = -1;
		for (int i = 1; i <= n; i++)
			if (a[i] != i - 1) {
				mex = i - 1; break;
			}
		if (mex == -1) {
			printf("%d\n", n + k);
			continue;
		}
		int res = (mex + a[n] + 1) / 2;
		bool flag = 0;
		for (int i = 1; i <= n; i++) if (res == a[i]) flag = 1;
		if (!flag) printf("%d\n", n + 1);
		else printf("%d\n", n);
	}
	
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
