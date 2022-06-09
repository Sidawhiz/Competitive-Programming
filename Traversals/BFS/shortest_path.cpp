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
int target;
int t = 0;

void bfs(int s){
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;

    while(!q.empty()){
        int fr = q.front();
        q.pop();
        for(int i : adj[fr]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
                par[i] = fr;
                dis[i] = 1 + dis[fr];
            }
            if(i==target){
                t = 1;
                break;
            }
        }
        if(t==1){
            return;
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

    cin >> a >> b;

    memset(par,-1,sizeof(par));
    memset(dis,-1,sizeof(dis));
    target = b;
    bfs(a);
    int temp = b;
    vector<int> path;
    while(temp!=-1){
        path.push_back(temp);
        temp = par[temp];
    }

    reverse(path.begin(),path.end());

    for(int i : path ){
        cout << i << " ";
    }
    cout << endl;

}
