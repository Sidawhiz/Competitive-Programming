#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 1000;
// const int mod = 1e9+7;

vector<int> adj[N];
int vis[N];
int par[N];
int dis[N];
queue<int> q;

void dfs(int s){
    //Base case
    if(vis[s]==1){
        return;
    }

    // Evaluate
    vis[s] = 1;
    for(auto i : adj[s]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int v,e;
    int a,b;
    cin >> v >> e;

    for(int i = 0; i<e ; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for(int i = 0; i<v; i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }

    cout << ans <<  endl;

}
