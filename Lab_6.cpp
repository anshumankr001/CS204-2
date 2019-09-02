#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
   ll n;
   cin>>n;
   vector<ll>v{0};
   pair<ll,ll>p;
   p = {-1,-1};
   while(n--)
   {
    ll a;
    cin>>a;
    if(a==1)
    {
        ll amt,id;
        cin>>id>>amt;
        v[id]+=amt;
        if(v[id]>p.second)
        {
            p = {id,v[id]};
        }
    }
    else if(a==2)
    {
        if(p.first==-1)
            cout<<"No data available"<<endl;
        else
            cout<<p.first<<endl;
    }
   }}
}
