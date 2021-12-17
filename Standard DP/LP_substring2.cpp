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


// MEMOISATION works better for this problem. Still, tried to do it with top-down approach

const int N = 1e3 + 5, MOD = 1e9+7 ;
string a ;

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
    int n = a.size();
    int l = 1;
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    //for len = 1
    for(int i = 0;i<n;i++){
        dp[i][i]=1;
    }
    int start=0 , end=0;
    // for len = 2
    for(int i = 0;i<n-1;i++){
        if(a[i]==a[i+1]){
            dp[i][i+1]=1;
            start = i;
            end = i+1;
        }
    }
    // DP over length i.e window length constant iteration
    // Also can be called two pointer method
    for(int i = 2;i<n;i++){
        for(int j = 0; j<n; j++){
            if(j+i<n && a[j]==a[j+i] && dp[j+1][j+i-1]==1){
                dp[j][j+i]=1;
                if(i>end-start+1){
                    start = j;
                    end = j+i;
                }
            }
        }
    }
    string f = "";
    for(int i = start; i<=end ; i++){
        f+=a[i];
    }
    cout << f << endl;

    return 0;
}
