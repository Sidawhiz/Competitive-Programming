```C++
vector<int> adj[N];
int vis[N]; 
int par[N]; // initialise all to -1
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
            dis[i] = 1 + dis[s];
            par[i] = s;
            dfs(i);
        }
    }
}
