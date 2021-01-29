#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int main()
{
	int T; cin >>T;
	while(T--){
		int n,k; cin >> n >> k;
		if(n == 1) printf("%d\n",k); 
		else{
			int t = k, sum = n, ans = 1;
			while(1){
				if(sum % k == 0){
					printf("%d\n",ans);
					break;
				}
				int left = k - (sum % k);
				
				if(left >= n) ans++, sum += n;
				else ans ++, sum += left;
				
			}
		}
	}
}
