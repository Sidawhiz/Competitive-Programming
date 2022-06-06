#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define push_back pb

const int N = 1000;

int nums[N];

int dp[N];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    nums[0] = 0;
    for(int i = 1 ; i<n+1 ; i++){
        cin >> nums[i];
    }
    dp[0] = 0;
    dp[1] = nums[1];
    for(int i = 2; i<n+1; i++){
        int f = nums[i];
        for(int j = 1 ; j<=i ; j++){
            f = max(f,dp[j]+dp[i-j]);
        }
        dp[i] = f;
    }
    cout << dp[n] << endl;

}
