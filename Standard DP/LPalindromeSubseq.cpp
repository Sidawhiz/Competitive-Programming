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
string a,b;
string lcs;
pair<int,string> dp[N][N];

pair<int,string> solve(int l , int m){
    //Base Case
    if(l<0 || m<0){
        pair<int,string> x = make_pair(0,"");
        return x;
    }
    //If already evaluated
    if(dp[l][m].first!=-1){
        return dp[l][m];
    }
    //If already not evaluated
    if(a[l]==b[m]){
        pair<int,string> x = solve(l-1,m-1);
        x.first+=1;
        x.second+=a[l];
        return dp[l][m]=x;
    }
    else{
        pair<int,string> x = solve(l,m-1);
        pair<int,string> y = solve(l-1,m);
        if(x.first>y.first){
            return dp[l][m] = x;
        }
        else{
            return dp[l][m] = y;
        }
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
    reverse(all(temp));
    b = temp;
    pair<int,string> y = make_pair(-1,"");
    for(int i = 0; i <N;i++){
        for(int j = 0; j<N ; j++){
            dp[i][j] = y;
        }
    }
    lcs = "";
    pair<int,string> ans = solve(a.size()-1,b.size()-1);
    cout << ans.first << " " << ans.second << endl;
}
