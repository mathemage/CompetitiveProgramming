#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define For(i,n)  for(int i=0;i<n;i++)
#define MOD 1000000007
#define MAX 100005
#define MAX2 10000
#define endl '\n'
#define Sort(v) sort(v.begin(), v.end())
using namespace std;
void show(int a[MAX], int n)
{
    For(i,n)
        cout<<a[i]<<" ";
    cout<<"\n";
}

void show1(int a[MAX2][MAX2], int r, int c)
{
    For(i,r)
    {
        For(j,c)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}



bool check(vi a ,int k)
{
    For(i,a.size())
    {
        if (a[i] == k)
            return true;
    }
    return false;
}
void show(vector<int> a)
{
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void show(vector<string> a)
{
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void show(vector<vector<int>> a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[i].size()-1;j++)
        {
            cout<<a[i][j]<<"/";
        }
        cout<<a[i][2]<<endl;
    }
}
int power(int r,int p)
{
    int k = 1;
    for(int i=0;i<p;i++)
    {
        k *= r;
    }
    return k;
}
int32_t main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        int n,k;
        cin>>n>>k;
        int temp = k;
        while(k < n)
        {
            k = k + temp;
            if (k >= n)
                break;
        }
        //cout<<n<<" "<<k<<endl;
        if (k>=n)
        {
            if(k%n == 0)
                cout<<k/n<<endl;
            else
                cout<<k/n + 1<<endl;
        }
    }
}
