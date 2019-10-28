#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
#define clr(x) x.clear()
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vi>
#define mp make_pair
#define hell 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

using namespace std;
using namespace __gnu_pbds;

void dfs(int v,int col,bool visited[],vi adj[],int color[]) {
    if(visited[v])
    {
        if(color[v]==col)
            return;
        else{
            cout<<"NO\n";
            exit(0);
        }
    }
    visited[v] = true;
    color[v]=col;
    for (int u : adj[v]) {
            dfs(u,col%2+1,visited,adj,color);
    }
}

int main()
{
    IOS
    int n,m;
    cin>>n>>m;
    vi adj[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int color[n+1];
    memset(color,-1,sizeof(color));
    bool visited[n+1];
    memset(visited,false,n+1);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]){
            color[i]=1;
            for(int j=0;j<adj[i].size();j++)
            {
                dfs(adj[i][j],2,visited,adj,color);
            }
        }
    }
    cout<<"YES\n";
    return 0;
}