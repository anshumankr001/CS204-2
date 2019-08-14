#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll t;
  cin>>t;
  for(ll i=0;i<t;++i)
  {
    string s;
    cin>>s;
    deque<char>v;
    ll count =0,flag=0;
    for(ll j=0;j<s.size();++j)
    {
      if(s[j]=='('||s[j]=='{'||s[j]=='['||s[j]=='<'||(s[j]=='|'&&count==0))
      {
        if(s[j]=='|')
          count++;
        v.push_back(s[j]);
      }
      else if((s[j]==')'||s[j]=='}'||s[j]==']'||s[j]=='>'||(s[j]=='|'&&count!=0))&&v.size()==0)
      {
        flag=1;
        break;
      }
      else
      {
        if(s[j]==')'&& v[v.size()-1]=='(')
        {
          v.pop_back();
        }
        else if(s[j]=='}'&& v[v.size()-1]=='{')
        {
          v.pop_back();
        }
        else if(s[j]==']'&& v[v.size()-1]=='[')
        {
          v.pop_back();
        }
        else if(s[j]=='>'&& v[v.size()-1]=='<')
        {
          v.pop_back();
        }
        else if(s[j]=='|'&& v[v.size()-1]=='|')
        {
          v.pop_back();
          count--;
        }
        else
          flag=1;
      }
    }
    //cout<<v.size()<<" "<<flag<<endl;
    if(flag==1||v.size()!=0)
      cout<<"NO"<<endl;
    else 
      cout<<"YES"<<endl;
  }
}