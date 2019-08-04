#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  ll t;
  cin>>t;
  for(ll i=0;i<t;i++)
  {
  vector<char>v1,v2;
  vector<ll>v3;
  string s1,s2;
  cin>>s1>>s2;
  for(ll i=0;i<s1.size();++i)
    v1.push_back(s1[i]);
  for(ll i=0;i<s2.size();++i)
    v2.push_back(s2[i]);
  if(v1.size()<v2.size())
    swap(v1,v2);
  reverse(v1.begin(),v1.end());
  reverse(v2.begin(),v2.end());
  ll minlen = min(v1.size(),v2.size());
  int carry = 0;
  for(ll i=0;i<minlen;++i)
  {
    ll num =(int)v1[i]-48+(int)v2[i]-48+carry;
    ll n1 = num;
    if(n1/10==0)
      carry =0;
    else
      carry=n1/10;
    v3.push_back(num%10);
  }
  if(v1.size()==v2.size())
  {
    if(carry!=0)
      cout<<carry;
    for(ll i=v3.size()-1;i>=0;i--)
      cout<<v3[i];
  }
  else if(v1.size()>v2.size())
  {
    if(carry==0)
    {
      for(ll i=v1.size()-1;i>=v2.size();i--)
        cout<<v1[i];
      for(ll i=v3.size()-1;i>=0;i--)
      cout<<v3[i];
    }
    else
    {
      for(ll i=v2.size();i<v1.size();i++)
      {
        ll num = (int)v1[i]-48+carry;
        ll n1 = num;
    if(n1/10==0)
      carry =0;
    else
      carry=n1/10;
    v3.push_back(num%10);
      }
      for(ll i=v3.size()-1;i>=0;i--)
      cout<<v3[i];
    }
  }
  cout<<endl;
 }
}