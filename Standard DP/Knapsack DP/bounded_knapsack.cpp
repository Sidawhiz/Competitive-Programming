#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define push_back pb

const int N = 1000;
int val[N];
int wt[N];
int bound[N];
int W;

int dp[N][N];

int solve(int n, int w, vector<int> boun){
    // Base Case
    if(n==0 || w==0){
        return 0;
    }

    // Already evaluated
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    // Else calculate further

    if(wt[n-1]<=w && boun[n-1]>0){
        boun[n-1]--;
        int c = val[n-1] + solve(n,w-wt[n-1],boun);
        boun[n-1]++;
        int d = solve(n-1,w, boun) ;
        if(c>d){
            boun[n-1]--;
            return dp[n][w] = c;
        }
        return dp[n][w] = d;
    }

    return dp[n][w] = solve(n-1,w,boun);

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

    vector<int> bound2(n);
    for(int i = 0; i<n ; i++){
        cin >> bound2[i];
    }

    int ans = solve(n,w, bound2);
    cout << ans << endl;

    for(int i = 0; i<4 ; i++){
        cout << bound2[i] << " ";
    }
}
