#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s;
vector<int> z;

void z_function(){
    int L = 0, R = 0;
    int n = s.size();
    for(int i = 1; i<n ; i++){
        if(i>R){
            L = i;
            R = i;
            while(R<n && s[R-L]==s[R]){
                R++;
            }
            z[i] = R-L;
            R--;
        }
        else{
            int dist_from_start = i-L;
            if(i + z[dist_from_start] <= R){
                z[i] = z[dist_from_start];
            }
            else{
                L = i;
                while(R<n && s[R-L]==s[R]){
                    R++;
                }
                z[i] = R-L;
                R--;
            }
        }
    }

}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    cin >> s;
    int n = s.size();
    vector<int> zz(n,0);
    z = zz;
    z_function();
    for(int i = 0; i<n; i++){
        cout<<z[i]<<" ";
    }
    cout<<endl;
    return 0;
}
