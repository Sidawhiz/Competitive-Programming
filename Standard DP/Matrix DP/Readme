#Matrix Chain Multiplication - standard code

1. Mind minimum cost to multiply chain of matrices : input array {40, 20, 30, 10, 30} : answer = 26000

```C++
int a[N];
int dp[N][N];

int solve(int i, int j){
    //Base Case
    if(j==i+1){
        return 0;
    }

    //Already evaluated
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //Else evaluate
    int ans = INT_MAX-1;

    for(int k = i+1; k<j ; k++){
        ans = min(ans, solve(i,k) + solve(k,j) + a[i]*a[k]*a[j]);
    }
    return dp[i][j] = ans;
}

int main(){

    int n;
    cin >> n;
    for(int i = 0; i<n ; i++){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0,n-1) << endl;

}```
