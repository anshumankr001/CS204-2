#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
int main()
{
  ll t;
  cin>>t;
  for(ll y=0;y<t;++y)
  {
  string s1,s2;
  cin>>s1>>s2;
  deque<ll>v1,v2,v3;
  for(ll i=0;i<s1.size();i++)
  {
    v1.push_back((int)s1[i]-48);
  }
  for(ll i=0;i<s2.size();i++)
  {
    v2.push_back((int)s2[i]-48);
  }
  reverse(v1.begin(),v1.end());
  reverse(v2.begin(),v2.end());
 if(s1.size()<s2.size())
  {
    swap(v1,v2);
    cout<<"-";
  }
  else if(s1.size()==s2.size())
  {
    for(int i=0;i<s1.length();i++)
       {
          if(s1[i]>s2[i]) break;
          if(s1[i]<s2[i])
          {
          swap(v1,v2);
          cout<<"-";
          break;
          }
          }
  }
    for(ll i=0;i<v2.size();i++)
    {
      if(v1[i]<v2[i])
      {
        ll k=1;
        while(v1[i+k]==0)
        {
          v1[i+k]=9;
          k++;
        }
        v1[i+k]-=1;
        v1[i]+=10;
      }
      v3.push_front(v1[i]-v2[i]);
    }
    for(ll i=v2.size();i<v1.size();i++)
      v3.push_front(v1[i]);
  for(ll i=0;i<v3.size();i++)
    cout<<v3[i];
  cout<<endl;
}
}