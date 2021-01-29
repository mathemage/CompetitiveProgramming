#include <bits/stdc++.h>

using namespace std;

int solve()
{
    long long n,k;
    cin>>n>>k;
    
    if(k>=n)
    {
        if(k%n==0)
        {
            cout<<k/n<<endl;
        }
        else
        {
            cout<<(k/n)+1<<endl;
        }
    }
    else
    {
   
        long long temp2=k;
        while(1)
        {
            temp2+=k;
            if(temp2>=n)
            {
                break;
            }
        }
        
        if(temp2%n==0)
        {
            cout<<temp2/n<<endl;
        }
        else
        {
            
            cout<<(temp2/n)+1<<endl;
        }
    }
    /*if(n==k)
    {
        cout<<"1\n";
    }
    else if(n<k)
    {   long long temp=n;
        while(1)
        {
            temp+=n;
            if(temp>=k)
            {
                cout<<temp/n<<endl;
                break;
            }
        }
    }
    else
    {
        long long temp=n;
        long long temp2=k;
        while(1)
        {
            temp2+=temp2;
            if(temp2>=n)
            {
                break;
            }
        }
        if(n==k)
        {
            cout<<"1\n";
        }
        while(1)
        {
            temp+=n;
            if(temp>=temp2)
            {
                cout<<temp/n<<endl;
                break;
            }
        }
        
        
    }
    */
    
    return 0;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       solve();
   }
   
   return 0;
}
