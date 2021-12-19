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
int dp[1000][1000];

int lcs(string a, string b, int m , int n){
    if(m==0 || n==0){
        return dp[m][n]=0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    else{
        if(a[m-1]==b[n-1]){
            return dp[m][n] = 1 + lcs(a,b,m-1,n-1);
        }
        else{
            return dp[m][n] = max(lcs(a,b,m,n-1),lcs(a,b,m-1,n));
        }
    }
}

int main(){
    // your code goes here
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        memset(dp,-1,sizeof(dp));
        int x = lcs(a,b,a.size(),b.size());
        int m = a.size(), n = b.size();
        string s = "";

        while(m!=0 || n!=0){
            if(m==0){
                while(n!=0){
                    s= a[n-1]+s;
                    n--;
                }
            }
            else if(n==0){
                while(m!=0){
                    s= a[m-1]+s;
                    m--;
                }
            }
            else if(a[m-1]==b[n-1]){
                s=a[m-1] + s;
                m--;
                n--;
            }
            else{
                if(dp[m-1][n]>dp[m][n-1]){
                    s = a[m-1]+s;
                    m--;
                }
                else{
                    s = b[n-1]+s;
                    n--;
                }
            }
        }
        cout << a.si+b.si-x << " " << s << endl;
    }
}
