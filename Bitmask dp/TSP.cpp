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

bool sortbysec(const pii &a, const pii &b){
    return (a.second < b.second);
}

//=========================CODE====================================

/*
Testcase
*/

ll n ;
vector<vector<int> > C;
ll dp[21][1<<21];
ll init_city;

ll solve(ll city, ll curr_city, ll mask, ll initial){
    if(city==n-1){
        //cout << "h" << C[curr_city][initial] << endl;
        return C[curr_city][initial] ;
    }

    if(dp[city][mask]!=-1){
        return dp[city][mask];
    }
    ll ans = INT_MAX;
    for(int i = 0; i<n ; i++){
        //cout << "Bye" << " " << curr_city << " " << i << endl; 
        if((i!=initial) && (i!=curr_city) && (mask & (1<<i))!=0){ // == and != has more priority than & , | , ^
            //cout << "Hi" << " " << curr_city << " " << i << endl; 
            ans = min(ans, C[curr_city][i] + solve(city + 1, i , mask ^ (1<<i) , initial) ); 
            //cout << ans << endl;
        }
    }
    return dp[city][mask] = ans ;
}


int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    vector<vector<int> > c;
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i<n ; i++){
        vector<int> tem;
        int temp;
        for(int j = 0; j<n ; j++){
            cin >> temp;
            tem.pb(temp);
        }
        c.pb(tem);
    }
    C = c;
    init_city = 0; // city to start with , by default zero i.e the first city
    ll ans = solve(0,init_city,(1<<n)-1,init_city);
    cout << ans << endl;
    return 0;
}





