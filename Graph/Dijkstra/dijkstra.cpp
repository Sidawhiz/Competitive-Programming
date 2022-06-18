#include <bits/stdc++.h>
#include <iostream>
 
using namespace std;
 
const int N = 1000; 
vector<pair<int,int> > adj[N] ;

vector<int> vis(N);
vector<int> par(N);
vector<int> dis(N);

priority_queue<pair<int,int> > q;

void dijkstra(int s){
    dis[s] = 0;
    par[s] = -1;
    q.push({0,s});
    while(!q.empty()){
        pair<int,int> f = q.top();
        int u = f.second;
        q.pop();
        if(vis[u]){ // don't forget this line , ensures n iterations only
            continue;
        }
        vis[u] = 1;
        for(auto v: adj[u]){
            int node = v.first;
            int dist_node = v.second;
            if(dis[u] + dist_node < dis[node]){
                dis[node] = dis[u] + dist_node;
                par[node] = u;
                q.push({-dis[node],node});
            }
        }
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int nodes, edges, source, u, v, w; 
    cin >> nodes >> edges >> source;

    for(int i = 0; i<nodes ; i++){
        dis[i] = 1e9 + 7;
    }

    
    for(int i = 0; i<edges ; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(source);
    for(int i = 0; i<nodes ; i++){
        cout << i << " " << par[i] << " " << dis[i] << endl;
    }
}
