#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 1000;
const int mod = 1e9+7;

vector<int> adj[N];
int dp[N];
int level[N];
int vis[N];

vector<pair<int,int>> bridge;

// cycle exists iff backedge exists

void dfs(int s, int par){
    // Base case
    if(vis[s]==1){
        return;
    }

    // else evaluate
    vis[s] = 1;
    level[s] =  (par==-1) ? 0 : 1 + level[par];
    for(auto i : adj[s]){
        if(!vis[i]){
            dfs(i,s);
            dp[s] = min(dp[s],dp[i]);
        }
        else{
            if(i != par && level[i] < level[s]){
                dp[s] = min(level[i],dp[s]);
            }
        }
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int v,e,a,b;
    cin >> v >> e;

    // undirected graph
    for(int i = 0; i<e ; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(level,0,sizeof(level));
    for(int i = 0; i<N; i++){
        dp[i] = mod;
    }

    for(int i = 0; i<v; i++){
        if(!vis[i]){
            dfs(i,-1);
        }
    }

    for(int i = 0; i<v ; i++){
        for(auto j: adj[i]){
            // cout << dp[j] << " " << level
            if(dp[j] > level[i]){
                if(i>j){
                    bridge.push_back({j,i});
                }
                else{
                    bridge.push_back({i,j});
                }
            }
        }
    }
    
    for(int i= 0; i<bridge.size(); i++){
        cout << bridge[i].first << " " << bridge[i].second << endl;
    }

}
