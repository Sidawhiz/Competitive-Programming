#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define push_back pb

const int N = 1000;
int val[N];
int wt[N];
int W;

int dp[N][N];

int solve(int n, int w){
    // Base Case
    if(n==0 || w==0){
        return 0;
    }

    // Already evaluated
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    // Else calculate further

    if(wt[n-1]<=w){
        return max( val[n-1] + solve(n,w-wt[n-1]), solve(n-1,w) );
    }

    return solve(n-1,w);

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,w;
    cin >> n >> w;
    W = w;

    // Assumption weight array is in ascending order

    memset(dp, -1 ,sizeof(dp));
    for(int i = 0; i<n ; i++){
        cin >> val[i];
    }

    for(int i = 0; i<n ; i++){
        cin >> wt[i];
    }

    int ans = solve(n,w);
    cout << ans << endl;
}
