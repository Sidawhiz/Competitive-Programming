#include <iostream>
#include <string>
using namespace std;

/* 
Let's call some positive integer classy if its decimal representation contains no more than 3 non-zero digits.
For example, numbers 4, 200000, 10203 are classy and numbers 4231, 102306, 7277420000 are not.

You are given a segment [𝐿;𝑅]. Count the number of classy integers 𝑥 such that 𝐿 ≤ 𝑥 ≤ 𝑅.

Each of the next 𝑇 lines contains two integers 𝐿𝑖 and 𝑅𝑖 ( 1 ≤ 𝐿𝑖 ≤ 𝑅𝑖 ≤ 10^18 ).
*/
string s;
int dp[20][20][2];

int solve(int pos , int cnt , int t){
    // Base case :
    if(cnt > 3){
        return 0;
    }
    if(pos == s.size()){
        if(cnt <= 3){
            return 1;
        }
        return 0;
    }

    // If not a base case : check if already evaluated

    if(dp[pos][cnt][t] != -1){
        return dp[pos][cnt][t];
    }

    // If already not evaluated , evaluate and store

    int lim;
    if(t==1){
        lim = 9;
    }
    else{
        lim = s[pos] - '0';
    }
    int ans = 0;
    int f = t;

    for(int i = 0 ; i <= lim ; i++){
        if (i != lim)
            f = 1;
        else
            f = t;
        if (i != 0)
            ans += solve(pos + 1, cnt + 1, f);
        else
            ans += solve(pos + 1, cnt, f);
    }
    dp[pos][cnt][t] = ans;
    //cout<<ans<<endl;
    return dp[pos][cnt][t];
}

int main()
{
    string a, b;
    cin >> a >> b; // input left and right bounds
    int t = a.size() - 1;
    while(a[t]=='0'){
        a[t]='9';
        t--;
    }
    a[t]--; // a converted to a-1;
    s = a;
    memset(dp,-1,sizeof(dp));
    int l = solve(0,0,0); // solve for a
    s = b; 
    memset(dp,-1,sizeof(dp));
    int r = solve(0,0,0); // solve for b 
    cout << "Number of such numbers are : " << r - l<<endl;
    return 0;
}
