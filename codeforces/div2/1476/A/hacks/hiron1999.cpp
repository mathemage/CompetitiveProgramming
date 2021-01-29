#include<bits/stdc++.h>
using namespace std;
#define swap(a,b) {int t=a;a=b;b=t;}
#define F(i,n) for(int i=0;i<n;i++)
#define ll long long 
int main(){
int t;
cin>>t;
while(t--){
double a, b;
cin>>a>>b;
int i=1;
while(b*i<a){
   i++;
}
b*=i;
if(a<=b) cout<<ceil(b/a);
else cout<<ceil(a/b);
cout<<"\n";
}
return 0;
}
