#include <bits/stdc++.h>
using namespace std;
//========================TypeDefs===================================
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

//=========================MACROS====================================
 
#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()
#define rbe rbegin()
#define ren rend()
#define all(v) v.be, v.en
#define rall(v) v.rbe, v.ren
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
 
#define forz(i, n) for (int i = 0; i < n; i++)
#define fore(i, m, n) for (int i = m; i <= n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define rfore(i, m, n) for (int i = n; i >= m; i--)
 
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define clz(n) __builtin_clz(n)
#define clzll(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctz(n)
 
#define bset(a, p) ((a) | (1ll << (p)))
#define bchk(a, p) ((a) & (1ll << (p)))
#define bxor(a, p) ((a) ^ (1ll << (p)));
#define brem(a, p) (bchk(a, p) ? (bxor(a, p)) : (a))
 
#define lb lower_bound
#define ub upper_bound
#define er equal_range
 
#define findnot find_first_not_of
 
#define maxe *max_element
#define mine *min_element
 
#define mod 1000000007
#define mod2 998244353
#define PI 3.1415926535897932384
#define INF LLONG_MAX
 
#define gcd __gcd
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

bool sortbysecasc(const pii &a, const pii &b){
    return (a.second < b.second);
}

//=========================CODE====================================

/*
Testcase

1
8 6
0 0 1 0 1 1
0 1 1 1 0 0
0 0 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 0 1 1 1 1
1 1 1 1 1 0
*/

int main(){
    // your code goes here
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    //Minimum cost to reach last cell from first cell
    //Easy straight forward dp : moves allowed right, bottom (variation can be done in moves allowed)
    int t;
    cin >> t;
    while(t--){
        int h,w;
        cin >> h >> w;
        int matrix[h][w];
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w ; j++){
                cin >> matrix[i][j];
            }
        }
        int dp[h][w];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w ; j++){
                if(i==0 && j==0){
                    dp[i][j] = matrix[i][j];
                }
                else if(i==0){
                    dp[i][j] = dp[i][j-1] + matrix[i][j];
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j] + matrix[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + matrix[i][j];
                }
            }
        }
        cout << dp[h-1][w-1] << endl;
    }    
    return 0;
}
