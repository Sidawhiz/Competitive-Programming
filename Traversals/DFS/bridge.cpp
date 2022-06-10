#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 1000;
// const int mod = 1e9+7;

vector<int> adj[N];
int dp[N];
int level[N];
int vis[N];

vector<pair<int,int>> bridge;

// cycle exists iff backedge exists

void dfs(int s, int lvl, int par){
    if(vis[s]){
        return;
    }

    vis[s] =1;
    level[s] = lvl;
    for(int i : adj[s]){
        if(!vis[i]){ // Tree edge
            dfs(i,lvl+1,s);
            dp[s] = min(dp[s],dp[i]);
            if(dp[i]<level[s]){
                bridge.push_back(make_pair(i,s));
            }
        }
        else if(vis[i]){ // Back edge - undirected doesn't have cross edge
            if(i!=par){
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

    for(int i = 0 ; i<e ; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp,INT_MAX-1,sizeof(dp));
    memset(level,-1,sizeof(level));

    dfs(0,0,-1);

    for(auto f : bridge){
        cout << f.first << " " << f.second << endl;
    }

}
