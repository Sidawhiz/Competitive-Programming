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

bool bfs(int s){
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;

    while(!q.empty()){
        int fr = q.front();
        q.pop();
        for(int i : adj[fr]){
            if(vis[i]==0){
                if(vis[fr]==1){
                    vis[i] = 2;
                }
                else{
                    vis[i] = 1;
                }
                q.push(i);
                par[i] = fr;
                dis[i] = 1 + dis[fr];
            }
            else if(vis[i]==vis[fr]){
                return false;
            }
        }
    }
    return true;
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

    memset(par,-1,sizeof(par));
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(vis));
    int x = bfs(0) ? 1 : 0;
    cout << x << endl;

}
