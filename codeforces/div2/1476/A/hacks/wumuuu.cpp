#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define Rep(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define DEBUG(x) cout << (x) << '\n'
ll a,b,c,d,x,y,l,r,t,n,m,sum=0,ans;
int main()
{
#ifdef zzy
    freopen("main.h", "r", stdin);
#endif // zzy
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin>>n;
    For(i,1,n)
    {
        cin>>a>>b;
        x=a;
        y=b;
        sum=0;
        while(y<x)
        {
            y+=b;
        }
        sum=y/x;
        if(y%x>0)
            sum+=1;
        DEBUG(sum);
    }
    return 0;
}

