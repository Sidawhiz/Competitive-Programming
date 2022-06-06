#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define push_back pb

const int N = 1000;

int nums[N];

int dp[N][N];
int dp2[N][N];

// tells if it is possible to have change
int solve2(int n , int sum){
    //Base case
    if(sum==0){
        return 1;
    }
    if(sum < nums[0]){
        return 0;
    }
    if(n==0){
        return 0;
    }

    if(dp2[n][sum] != -1){
        return dp2[n][sum];
    }

    if(sum >= nums[n-1]){
        return dp2[n][sum] = (solve2(n-1,sum-nums[n-1]) || solve2(n-1,sum));
    }

    return dp2[n][sum] = solve2(n-1,sum);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(dp2,-1,sizeof(dp));
    int n;
    cin >> n;
    for(int i = 0 ; i<n ; i++){
        cin >> nums[i];
    }

    int sum = 0;
    for(int i = 0; i<n ; i++){
        sum+=nums[i];
    }
    if(sum%2!=0){
        cout << 0 << endl;
    }
    else{
        cout << solve2(n,sum/2) << endl;
    }
}
