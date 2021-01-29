#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k,op;
        cin>>n>>k;
        if(n==k)
        cout<<1<<endl;
        else if(n<k)
        {
            int i=0;
            while(1)
            {
                i++;
                if(n*i>=k)
                {
                    op=i;
                    break;
                }
            }
            cout<<op<<endl;
        }
        else if(n>k)
        {
            if(n%k==0)
            cout<<1<<endl;
            else
            cout<<2<<endl;
        }
    }

    return 0;
}
