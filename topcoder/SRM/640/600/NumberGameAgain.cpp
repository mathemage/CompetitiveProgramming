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

using namespace std;

#define MSG(a) cout << #a << " == " << a << endl;
typedef vector<long long> vll;
typedef long long ll;

class NumberGameAgain {
public:
	long long solve(int, vll);
};

long long NumberGameAgain::solve(int k, vll table) {
	ll tot = 1;
	for (int i = 1; i <= k; i++) {
		tot *= 2;
	}
	tot-=2;
	sort(table.begin(), table.end());
	
	int sz = table.size();
	vector<bool> invalid(sz, false);
	vector<int> width(sz);

	for (int i = 0; i < sz; i++) {
		ll t = table[i];
		while (t) {
			t >>= 1;
			width[i]++;
		}	
	}
	
	for (int i = 0; i < sz-1; i++) {
		if (invalid[i]) continue;
		for (int j = i+1; j < sz; j++) {
			int shift = width[j]-width[i];
//			if (invalid[j] == false && shift >= 0) {
			if ( table[i] == (table[j] >> shift) ) {
				invalid[j] = true;
		//		printf("%lld invalidated by %lld \t invalid[%d] == %d \n", table[j], table[i], j, invalid[j] ? "true" : "false");
			}
		}
	}

	for (int i = 0; i < sz; i++) {
//		pritnf("%d ", invalid[i]);
		//MSG(table[i]) MSG(invalid[i])
		if (!invalid[i]) {
			int a = (k-width[i]+1);
			MSG(a) MSG(1 << a)
			tot -= (1 << a ) - 1;
		}
	}
	
	return tot;
}


//Powered by [KawigiEdit] 2.0!
