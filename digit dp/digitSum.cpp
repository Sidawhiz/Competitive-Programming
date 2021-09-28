#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
For a pair of integers a and b, the digit sum of the interval [a,b] is defined as 
the sum of all digits occurring in all numbers between (and including) a and b. 
For example, the digit sum of [28, 31] can be calculated as:
2+8  +  2+9  +  3+0  +  3+1 = 28

Given the numbers a and b, calculate the digit sum of [a,b].

 a and b (0 <= a <= b <= 10^15).
*/

typedef long long int ll;
const ll mod = 1e9 + 7;

vector<int> num;
ll dp[300][2][300];//pos,restricted,sum
 
ll call(int pos,int f1,int sum){
    if(pos==num.size()){
        return sum;
    }
 
    ll ret = dp[pos][f1][sum];
    if(ret!=-1) return ret;
 
    int LIM = f1 ? 9 : num[pos];
    ll ans = 0;
 
    for(int i=0;i<=LIM;i++){
        ans += call(pos+1,i<num[pos] ? 1 : f1 ,sum+i );
    }
    dp[pos][f1][sum] = ans;
    return ret = ans;
}
 
ll solve(int x){
    num.clear();
    while(x){
        num.push_back(x%10);
        x/=10;
    }
    reverse(num.begin(),num.end());
    memset(dp,-1,sizeof(dp));
    return call(0,0,0);
}
 
 
int main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        cout<<solve(b)-solve(a-1)<<endl;
    }
    return 0;
}
