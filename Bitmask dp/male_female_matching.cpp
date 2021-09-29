#include <iostream>
using namespace std;
#include <bits/stdc++.h>
/*

https://atcoder.jp/contests/dp/tasks/dp_o

There are N men and N women, both numbered 1,2,…,N.

For each i,j (1≤i,j≤N), the compatibility of Man i and Woman j is given as an integer a 
i,j
. If a[i,j] =1, Man i and Woman j are compatible; if a[i,j] =0, they are not.

Taro is trying to make N pairs, each consisting of a man and a woman who are compatible. Here, each man and each woman must belong to exactly one pair.

Find the number of ways in which Taro can make N pairs, modulo 10^9 +7.

All values in input are integers.
1≤N≤21
a[i,j] is 0 or 1.
*/

// assign man to woman or assign woman to man
#define mod 1000000007
int cost[22][22];
int dp[22][(1<<22)];

int solve(int i , int mask, int n){
    if(mask==0){
        return 1;
    }
    if(i>=n){
        return 0;
    }

    if(dp[i][mask]!=-1){
        return dp[i][mask];
    }
    int ans = 0;

    for(int j = 0; j<n;j++){
        if(((mask) & (1<<j))==0){
            continue;
        }
        if(cost[i][j]==0){
            continue;
        }
        else{
            ans = (ans + solve(i+1,(mask ^ (1<<j)),n))%mod;
        }
    }
    return dp[i][mask] = ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    int a;
    int k , kk;
    k = t;
    kk = t; 
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i<t;i++){
        for(int j = 0; j<t;j++){
            cin >> a;
            cost[i][j]=a;
        }
    }

    int ans = solve(0,(1<<t)-1,t);
    cout << ans << endl;
}
