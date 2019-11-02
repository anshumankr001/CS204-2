#include<bits/stdc++.h>

using namespace std;

#define lli long long
bool visit(lli x,vector<vector<lli>> v, short c, vector<short> C)
{
    for(lli i=0;i<v[x].size();i++)
    {
        if(C[v[x][i]]==c)
        return false;
        else if(C[v[x][i]]==-1)
        {
            C[v[x][i]]=1-c;
            if(!visit(v[x][i],v,C[v[x][i]],C))
            return false;  
        }
    }
    return true;
}

int main()
{
    lli n,m;
    cin>>n>>m;
    vector<vector<lli>> v(n);
    lli x,y,w;
    vector<short> C(n);
    for(lli i=0;i<n;i++)
    C[i]=-1;
    for(lli i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        if(w%2)
        {
            v[x-1].push_back(y-1);
            v[y-1].push_back(x-1);
        }
        else 
        {
            v.push_back({x-1,y-1});
            v[x-1].push_back(v.size()-1);
            v[y-1].push_back(v.size()-1);
            C.push_back(-1);
        }
    }
    // for(int i=0;i<n;i++)
    // cout<<C[i];
    // for(lli i=0;i<v.size();i++)
    // for(int j=0;j<v[i].size();j++)
    // cout<<v[i][j]<<'c'<<i<<' ';
    // cout<<endl;
    for(lli i=0;i<v.size();i++)
    {
        if(C[i]==-1)
            if(!visit(i,v,0,C))
            {
                cout<<"YES"<<endl;
                return 0;
            }
    }
    cout<<"NO"<<endl;
    return 0;

}
