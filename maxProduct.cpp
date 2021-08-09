#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
typedef long long int ll;

/*
https://codeforces.com/problemset/gymProblem/100886/G

Find the number from the range [a,b] which has the maximum product of the digits.

Input
The first line contains two positive integers a and b (1≤a≤b≤10^18): 
the left and the right ends of the range.

Output
Print the number with the maximum product of the digits from the range [a,b]. If there are several possible answers, print any one of them.
*/

string t,s;
pair<ll,string> dp[20][2][2][2];
// first - stores the multiplication /// second stores - string that produces that multiplication

pair<ll,string> solve(int pos, int t1 , int t2, int srt){ // use of srt let a = 001023 srt helps to differ between zeroes earlier and after
    // Base case
    if(pos == t.size()){
        pair<ll,string> tmp;
        tmp = make_pair(1,"");
        return tmp;
    }

    // already evaluated
    if(dp[pos][t1][t2][srt].first!=-1){
        return dp[pos][t1][t2][srt];
    }

    // already not evaluated
    int up = t1 ? 0 :t[pos] - '0';
    int down = t2 ? 9 : s[pos] - '0';

    ll rest = -1;
    string ans = "";
    int f1 = t1;
    int f2 = t2;
    int srt2 = srt;

    for(int i = up ; i<=down ; i++){
        ll val;
        if(srt==0 && i==0){
            val = 1;
        }
        else{
            val = i;
        }
        f1 = (i>up)? 1 : t1;
        f2 = (i<down) ? 1 : t2;
        if(i>0){
            srt2 = 1; 
        }
        else{
            srt2 = srt;
        }
        pair<ll,string> k = solve(pos+1,f1,f2,srt2);

        if((val * k.first) > rest){
            rest = val * k.first;
            if(srt==0 && i==0){
                ans = k.second; // for forward zeroes string won't change
            }
            else{
                ans = to_string(i)[0] + k.second;
            }
        }
    }
    pair<ll,string> tem;
    tem = make_pair(rest,ans);
    return dp[pos][t1][t2][srt] = tem;
}

int main(){
    string left, right;
    cin >> left >> right;
    for(int i = 0; i<20 ; i++){
        for(int j = 0; j<2;j++){
            for(int k = 0; k<2;k++){
                for(int l = 0 ; l<2;l++){
                    pair<ll,string> tm;
                    tm = make_pair(-1,"");
                    dp[i][j][k][l] = tm;
                }
            }
        }
    }

    reverse(left.begin(),left.end()); // If a = 12 b = 4000
    while(left.size()<right.size()){
        left.push_back('0');
    }
    reverse(left.begin(),left.end()); // a becomes 0012

    t = left;
    s = right;
    pair<ll,string> ans = solve(0,0,0,0);
    cout << "Answer is : " << ans.second << endl;

    return 0;
}