#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 1000;
// const int mod = 1e9+7;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second < b.second){
        return true;
    }
    return false;
}

vector<int> adj[N];
vector<pair<int,int>> topo_sort;
int vis[N];
int arr[N];
int dep[N];
int cnt;
int ans = 0;

// cycle exists iff backedge exists

void dfs(int orig_source,int s){
    //Base case
    if(vis[s]==1){
        return;
    }

    // Evaluate
    vis[s] = 1;
    arr[s] = cnt++;
    for(auto i : adj[s]){
        if(!vis[i]){
            dfs(orig_source ,i);
            dep[i] = cnt++;
            topo_sort.push_back(make_pair(i,dep[i]));
        }
        else if(vis[i]){
            if(dep[i]==-1){
                ans=1;
            }
        }
    }
    if(s==orig_source){
        dep[s] = cnt++;
        topo_sort.push_back(make_pair(s,dep[s]));
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
    memset(vis,0, sizeof(vis));
    memset(arr,-1,sizeof(arr));
    memset(dep,-1,sizeof(dep));

    vector<int> topo_order;
    //visiting every vertex only once, hence O(V+E)
    for(int i = 0; i<v ; i++){
        cnt = 0;
        if(!vis[i]){
            dfs(i,i);
        }    
        sort(topo_sort.begin(),topo_sort.end(),sortbysec);
        for(int i = 0; i<topo_sort.size() ; i++){
            topo_order.push_back(topo_sort[i].first);
        }
        topo_sort.clear();
    }    

    for(int i = topo_order.size()-1; i>=0 ; i--){
        cout << topo_order[i]<< " ";
    }
    cout << endl;


}
