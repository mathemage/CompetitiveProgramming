#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,k,c=0;
        cin >> n;
        cin >> k;
        int temp1=n/k;
        int temp2=k*(temp1+1);
        if(n%k==0)
        {
            cout << 1 << endl;
            continue;
        }
        for(int j=0;temp2>n;j++)
        {
            temp2-=n;
            c++;
        }
        cout << (c+1) << endl;
    }
    return 0;
}
