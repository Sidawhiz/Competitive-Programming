#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 1000;
// const int mod = 1e9+7;

vector<int> adj[N];
int vis[N];
int arr[N];
int dep[N];
int cnt;
int ans = 0;

// cycle exists iff backedge exists
// worst case is to run dfs from every node - O[V*(V+E)]
void dfs(int s){
    //Base case
    if(vis[s]==1){
        return;
    }

    // Evaluate
    vis[s] = 1;
    arr[s] = cnt++;
    for(auto i : adj[s]){
        if(!vis[i]){
            dfs(i);
            dep[i] = cnt++;
        }
        else if(vis[i]){
            if(dep[i]==-1){
                ans=1;
            }
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
    }
    for(int i = 0; i<v ; i++){
        memset(vis,0, sizeof(vis));
        memset(arr,-1,sizeof(arr));
        memset(dep,-1,sizeof(dep));
        cnt = 0;
        dfs(i);
        if(ans == 1){
            break;
        }
    }    

    cout << (ans ? "Yes " : "No ") <<  endl;


}
