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


vi z_function(string s){
    int l = 0, r=0 , n =s.size();
    vi z(n,0);
    for(int i = 1 ; i<n ; i++){
        if(i>r){
            l = r = i;
            while(r<n && s[r-l]==s[r]){
                r++;
            }
            z[i] = r-l;
            r--;
        }
        else{
            int dist = i-l;
            if(i + z[dist] <= r){
                z[i] = z[dist];
            }
            else{
                l = i; 
                dist = 0;
                while(r<n && s[r-l]==s[r]){
                    r++;
                }
                z[i] = r-l;
                r--;
            }
        }
    }
    return z;
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
    vector<int> z;
    z = z_function(s);
    for(int i = 0; i<n; i++){
        cout<<z[i]<<" ";
    }
    cout<<endl;
    return 0;
}
