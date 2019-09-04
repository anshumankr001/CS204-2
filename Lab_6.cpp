#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long find(vector<long long> v,long long k)
{
    long long start=0,end=v.size()-1,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(v[mid]>k)
            end=mid-1;
        else if(v[mid]<k)
            start=mid+1;
        else return mid;
    }
    return -1;
}
int main()
{
    ll n,q,maxid=-1;
    cin>>n>>q;

    ll x,y,z;
    vector<vector<ll>> v;
    vector<long long> w;
    for(int i=0;i<q;i++)
    {
        cin>>x;
        if(x==1)
        {
            cin>>y>>z;
            w.push_back(y);
            v.push_back({x,y,z});
        }
        else v.push_back({2});
    }
    sort(w.begin(),w.end());
    vector<ll> u;
    for(int i=0;i<w.size();i++)
    {
        if(!i)
            u.push_back(w[i]);
        if(w[i]!=w[i-1])
            u.push_back(w[i]);
    }
    ll am[u.size()]={0};
    for(int i=0;i<q;i++)
    {
        if(v[i][0]==1)
        {
            long long p=find(u,v[i][1]);
            am[p]+=v[i][2];
            //cout<<u[p]<<' '<<am[p]<<endl;
            if(maxid==-1||am[p]>am[maxid])
            {
                maxid=p;
                //cout<<i<<'o'<<endl;
            }
        }
        else
        {
            if(maxid==-1)
                cout<<"No data available."<<endl;
            else cout<<u[maxid]<<endl;
        }
    }
}