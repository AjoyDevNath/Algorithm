#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
const int INF = 1e9 + 10;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

vector<int>adj[100001];

bool dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&color,int c)
{
    vis[node] = 1;
    color[node] = c;

    for(auto child : adj[node])//2
    {
        if(vis[child] != 1)//(vis[])
        {
            if(dfs(child,vis,adj,color,c^1) == false)
            {
                return false;
            }
        }
        else
        {
            if(color[child] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    int node,edge;
    cin>>node>>edge;
    for(int i = 0 ; i < edge ; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int>vis(node,0);
    vector<int>color(node,0);

    for(int i = 1 ; i <= node ; i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,adj,color,1) == false)
            {
                cout<<"Not Bipartate\n";
                return;
            }
        }
    }
    cout<<"Bipartate graph\n";
}

int main()
{
    fastIO();
    solve();
}
