#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define push_back pb

const int N = 1000;
int coins[N];

int dp[N][N];

int solve(int n, int t){
    // Base case - if target is 0 then there is 1 way to fulfill this i.e empty set
    // But if coins are 0 then there is no way to fulfill any target i.e null set

    if(t==0){
        return 1;
    }
    if(n==0){
        return 0;
    }

    if(dp[n][t]!=-1){
        return dp[n][t];
    }

    if(coins[n-1]<=t){
        return dp[n][t] = solve(n,t-coins[n-1]) + solve(n-1,t);
    }

    return dp[n][t] = solve(n-1,t);

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t,n;
    cin >> t >> n;
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i<n ; i++){
        cin >> coins[i];
    }

    int ans = solve(n,t);
    cout << ans << endl;
}
