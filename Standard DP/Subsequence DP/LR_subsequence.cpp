#include <bits/stdc++.h>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mod 1000000007

bool sortbysecasc(const pi &a, const pi &b){
    return (a.second < b.second);
}

const int N = 1e3 + 5, MOD = 1e9+7 ;
string a,b;
int dp[N][N];

int solve(int l , int m){
    if(l<0 || m<0){
        return 0;
    }
    if(dp[l][m]!=-1){
        return dp[l][m];
    }
    else if(a[l]==b[m]){
        return dp[l][m] = solve(l-1,m-1) + 1;
    }
    else{
        return dp[l][m] = max(solve(l,m-1),solve(l-1,m));
    }
}

int main(){
    // your code goes her
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    fast
    string temp;
    cin >> temp;
    a = temp;
    cin >> temp;
    b = temp;
    memset(dp,-1,sizeof(dp));
    int ans = solve(a.size()-1,b.size()-1);
    cout << ans << endl;
}
