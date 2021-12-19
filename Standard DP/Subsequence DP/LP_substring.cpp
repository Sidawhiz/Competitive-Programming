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
int dp[N][N];
string a ;

int startfromcentre(int l , int r){
    if(l>r){
        return 0;
    }
    while(l>=0 && r<a.size() && a[l]==a[r]){
        l--;
        r++;
    }
    return r-l-1;
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
    int start = 0, end =0;
    int n = a.size();
    int l = 0;
    for(int i = 0; i<n ; i++){
        int l1 = startfromcentre(i,i);
        int l2 = startfromcentre(i,i+1);
        l = max(l1,l2);
        if(l>end-start){
            start = i - (l-1)/2;
            end = i + l/2;
        }
    }
    string f = "";
    for(int i = start; i<=end; i++){
        f+=a[i];
    }
    cout << start << " " << end << " " << f << endl;
}
