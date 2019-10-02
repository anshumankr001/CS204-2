#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
struct point{
  ll x,y;
};
point p0;
point nexttostack(stack<point> s){
    point a= s.top();
    s.pop();
    point p=s.top();
    s.push(a);
    return p;
}

ll orientation(point a,point b,point c)
{
  ll x = (b.y-a.y)*(c.x-b.x) - (c.y-b.y)*(b.x-a.x);
    if(x==0){
        return 0;
    }
    if(x>0){
        return 1;
    }
    else{
        return 2;
    }
}
ll dis(point p1,point p2)
{
  return (p1.x-p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
bool compare(point x,point y){
  ll o=orientation(p0,x,y);
  if(o==0)
  {
    if(dis(p0,x)>=dis(p0,y))
      return 0;
    else
      return 1;
  }
  else if(o==1)
    return 1;
  return 0;
}
void convexhull(vector<point>v,ll n)
{
  ll xmin = v[0].x,min=0;
  for(ll i=1;i<n;i++)
  {
    ll x = v[i].x;
    if((x<xmin)||(xmin==x&&v[i].y<v[min].y))
      xmin = v[i].x,min=i;
  }
  swap(v[0],v[min]);
  p0=v[0];
  auto it = v.begin();
  it++;
  sort(it,v.end(),compare);
  vector<point>v1;
  v1.push_back(p0);
  for(ll i=1;i<n;i++)
  {
    while(i<n-1&&orientation(p0,v[i],v[i+1])==0)
      i++;
    v1.push_back(v[i]);
  }
  if(v1.size()<3)
  {
    cout<<"Convex Hull Not Possible";
    return ;
  }
  stack<point>s,s1;
  s.push(v1[0]);
  s.push(v1[1]);
  s.push(v1[2]);
  for(ll i=3;i<v1.size();i++)
  {
    while(orientation(nexttostack(s),s.top(),v1[i])!=1)
      s.pop();
    s.push(v1[i]);
  }
  while(!s.empty())
  {
   s1.push(s.top());
   s.pop();
  }
  cout<<s1.size()<<endl;
  while(!s1.empty())
  {
    point p = s1.top();
    cout<<p.x<<" "<<p.y<<endl;
    s1.pop();
  }
}
int main()
{
  ll t;
  cin>>t;
  vector<point>v;
  for(ll i=0;i<t;i++)
  {
    ll x,y;
    cin>>x>>y;
    point p;
    p.x=x;
    p.y=y;
    v.push_back(p);
  }
  convexhull(v,t);
  return 0;
}