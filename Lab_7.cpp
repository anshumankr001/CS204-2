#include<bits/stdc++.h>

using namespace std;

bool compare(string s1,string s2)
{
  string t1=s1+s2,t2=s2+s1;
  if(t1>t2)
    return true;
  return false;

}
int main()
{
  long long t;
  cin>>t;
  while(t--)
  {
    long long q;
    cin>>q;
    string s[q];
    for(int i=0;i<q;i++)
      cin>>s[i];
    sort(s,s+q,compare);
    for(int i=0;i<q;i++)
    {
      cout<<s[i];
    }
    cout<<endl;
  }
  return 0;
}