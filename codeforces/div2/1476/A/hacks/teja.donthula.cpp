#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n,k,c=1,j=0;
		cin>>n>>k;
		if(n>k){
			if(n%k) k=((n/k)+1)*k;
			else k=n;
		}
		j=c*n;
		while(k>j){
			++c;
			j=c*n;
		}
		cout<<c<<endl;
	}
	return 0;
}
