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


// Done by memoisation

const int N = 1e3 + 5, MOD = 1e9+7 ;
string a,b;
string lc_substr;
int dp[N][N];

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
    int y = 0;
    for(int i = 0; i <N;i++){
        for(int j = 0; j<N ; j++){
            dp[i][j] = y;
        }
    }
    //lcs = "";
    for(int i=1; i<=a.size();i++){
        for(int j = 1; j<=b.size() ; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
        }
    }
    int ans = 0;
    string str = "";
    for(int i=0; i<=a.size();i++){
        for(int j = 0; j<=b.size() ; j++){
            //cout << dp[i][j] << " ";
            ans = max(ans,dp[i][j]);
        }
        //cout << endl ;
    }
    int p,q;
    for(int i=0; i<=a.size();i++){
        for(int j = 0; j<=b.size() ; j++){
            if(dp[i][j]==ans){
                p = i;
                q = j;
                break;
            }
        }
    }
    for(int i = 0; i<ans; i++){
        str=a[p-1]+str;
        p--;
    }
    cout << ans << " " << str << endl;
}
