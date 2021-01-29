#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        double n,k;
        cin>>n>>k;
        double x = k/n;
        if(x<1)
        {
            double z = k;
            while(k/n < 1)
            {

                k = k+z;
            }
            x = k/n;
            long long y = ceil(x);
            cout<<y<<endl;
        }
        else if(x>1)
        {
            long long y = ceil(x);
            cout<<y<<endl;
        }
        else{
            long long y = k/n;
            cout<<y<<endl;
        }

    }

    return 0;
}
