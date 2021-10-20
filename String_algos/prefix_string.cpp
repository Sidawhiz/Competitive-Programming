#include <bits/stdc++.h>
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
#define mod 1000000007

vi prefix_function(string s){
    int n = s.size();
    vi pi(n,0);
    for(int i = 1; i<n ; i++){
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    /*for(int i = 0 ; i<n ; i++){
        cout << pi[i] << " ";
    }
    cout<<endl;*/
    return pi;
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    int n = s.size();
    vector<int> p;
    p = prefix_function(s);
    for(int i = 0; i<n; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return 0;
}
