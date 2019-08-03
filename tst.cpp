#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
string add(string s1,string s2)
{
   char a='0';
    int p=0,t;
    if(s1.length()<s2.length())
    {
       string temp=s1;
       s1=s2;
       s2=temp;
    }
    while(s2.length()<s1.length())
    {
       s2.push_front('0');
    }   
    
    string result="";                                            
    for(int i=s1.length()-1; i>=0  ;i--)
    { 
         
        t= (int)(s1[i]-'0') + (int)(s2[i] -'0') + p;
        p=t/10;
        t=t%10;
        result.push_back((char) (t + (int)a )) ;
     }
     if(p==1) result.push_back('1');
      
      reverse(result.begin(), result.end());
     return result;
}
int main()
{
  string s1,s2;
  cin>>s1>>s2;
  string r =add(s1,s2);
  cout<<r;
}
/*ll binarysearch(string l,string r,string s1,string s2)
{
  string mid = add(l,r);
  if(n1-mid*n2<=n2&&n1-mid*n2>=0)
  {
    if(n1-mid*n2==n2)
    return mid+1;
  else
    return mid;
  }
  else if(n1-mid*n2>n2)
    return binarysearch(mid+1,r,n1,n2);
  else
    return binarysearch(l,mid-1,n1,n2);
}
int main()
{
  string s1,s2;
  cin>>s1>>s2;
  string s3;
  s3.push_back('1');
  for(ll i=0;i<s1.size();i++)
    s3.push_back('0');
  for(ll i=0;i<s3.size();i++)
    cout<<s3[i];
  ll q = binarysearch(1,num,s1,s2);
  cout<<q;
}*/