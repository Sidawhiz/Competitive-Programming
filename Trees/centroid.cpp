const int N = 2e5 + 5;
int n, nodes, eu, ev;
int siz[N], par_centroid[N];
set<int> adj[N];

// assigns size of subtrees
void dfs(int s, int e)
{
    nodes++;
    siz[s] = 1;
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dfs(u, s);
        siz[s] += siz[u];
    }
}

// finds centroid for tree indexed at s
int centroid(int s, int e)
{
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        if (siz[u] > nodes / 2)
          // recursion works as we shift to node with nodes > n/2 , we increase size of other subtree by only 1
          // hence condition for nodes is constant nodes/2 
            return centroid(u, s);
    }
    return s;
}

// this builds centroid tree
void decompose(int s, int e)
{
    nodes = 0;
    dfs(s, s);
    int node = centroid(s, s);
    par_centroid[node] = e;
    for (auto u : adj[node])
    {
        adj[u].erase(node);
        decompose(u,node);
    }
}

int main()
{
    kira;
    cin >> n;
    forz(i, n - 1)
    {
        cin >> eu >> ev;
        adj[eu].insert(ev);
        adj[ev].insert(eu);
    }
    decompose(1, 0);
    run_time();
    return 0;
}
