#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long int ll;

// kind of fails for input digit if 0

/*  
Given a set of digits S, and an integer n, 
you have to find how many n-digit integers are there, 
which contain digits that belong to S and t
he difference between any two adjacent digits is not more than two.

Each case contains two integers, m (1 ≤ m < 10) and n (1 ≤ n ≤ 10). 
The next line will contain m integers (from 1 to 9) separated by spaces. 
These integers form the set S as described above. 
These integers will be distinct and given in ascending order.
*/
string s;
int dp[12][12][12];
vector<bool> num(10,false);

int solve(int pos,int r1, int r2){
    if(pos == s.size()){
        return 1;
    }

    if(dp[pos][r1][r2]!=-1){
        return dp[pos][r1][r2];
    }

    int ans = 0;
    for(int i = r1 ; i<=r2 ; i++){
        if(num[i] == false){
            continue;
        }
        int ji = i - 2;
        if(ji < 0 ){
            ji =0;
        }
        int ki = i + 2;
        if(ki>9){
            ki = 9;
        }
        ans += solve(pos+1,ji,ki);
    }
    dp[pos][r1][r2] = ans;
    return dp[pos][r1][r2];
}


int main(){
    int m , n; // n-digit numbers only
    cin >> m >> n;
    int t = n-1;
    int val;

    while(m--){
        cin >> val;
        num[val] = true;
    }

    string b = "";
    for(int i = 0; i<t+1;i++){
        b += '9';
    }
    s = b;
    cout << b << endl;
    memset(dp,-1,sizeof(dp));
    int r = solve(0,1,9);

    cout << "Number of such numbers are : " << r << endl;
}