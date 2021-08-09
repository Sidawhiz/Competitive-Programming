#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
typedef long long int ll;

/*
https://www.codechef.com/problems/MPRODMUL

Chef is given three numbers A, B and K. Chef considers an integer x valid, that satisfies these conditions:

1. x  is a multiple of K, i.e. x % K=0
2. x ∈ [A, B]
3. ∀ di ∃ dj (di % dj = 0) where 0≤i<j≤len(x)−1, where len(x) denotes the number of digits in decimal representation of x
   In simple terms, for each digit except dlen(x)−1, there must exist a digit dj to the right of di such that dj divides di.
4. x  uses only non-zero digits.

Let F(n) be a function that returns the product of digits of n.

Among all valid x, Chef needs to find x with maximum possible positive F(x). 
If many such x exist, Chef is asked to find the smallest such x.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers A, B and K

Output
If there is no such x, print a single integer −1.
Otherwise, print a single line containing two integers - F(x) and x.

Constraints
1≤T≤100     1≤A≤B≤10^18      1≤K≤100
*/

int KK;
string t,s;
pair<ll,string> dp[20][2][2][2][180][10];
pair<ll,string> solve(int pos, int t1, int t2, int str , int sum,int prev){
    //Base case
    if(pos == t.size()){
        if(sum==0){
        pair<ll,string> tmp;
        tmp = make_pair(1,"");
        return tmp;}
        else{
            pair<ll,string> tmp;
            tmp = make_pair(0,"");
            return tmp;
        }
    }

    // already evaluated
    if(dp[pos][t1][t2][str][sum][prev].first!=-1){
        return dp[pos][t1][t2][str][sum][prev];
    }

    // already not evaluated
    int up = t1 ? 0 :t[pos] - '0';
    int down = t2 ? 9 : s[pos] - '0';

    ll rest = -1;
    string ans = "";
    int f1 = t1;
    int f2 = t2;
    int srt2 = str;
    int sum2 = sum;
    int prev2=prev;

    for(int i = up ; i<=down ; i++){
        if(str!=0 && i==0){
            continue;
        }
        if(i!=0 && prev2%i!=0){
            continue;
        }
        ll val;
        if(str==0 && i==0){
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
            srt2 = str;
        }
        sum2 = (10*sum + i)%KK;
        pair<ll,string> k = solve(pos+1,f1,f2,srt2,sum2,i);
        if((val * k.first) > rest){
            rest = val * k.first;
            if(str==0 && i==0){
                ans = k.second; // for forward zeroes string won't change
            }
            else{
                ans = to_string(i)[0] + k.second;
            }
        }
    }
    pair<ll,string> tem;
    tem = make_pair(rest,ans);
    return dp[pos][t1][t2][str][sum][prev] = tem;
}

int main(){
    int tt,kv;
    cin >>tt;
    string left, right ;
    while(tt--)
    {
        cin >> left >> right >> kv;
        KK = kv;
        for(int i = 0; i<20 ; i++)
        {
            for(int j = 0; j<2;j++)
            {
                for(int k = 0; k<2;k++)
                {
                    for(int l = 0 ; l<2;l++)
                    {
                        for(int m = 0 ; m < 180; m++)
                        {
                            for(int n = 0; n<10 ; n++)
                            {
                                pair<ll,string> tm;
                                tm = make_pair(-1,"");
                                dp[i][j][k][l][m][n] = tm;
                            }
                        }
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
        pair<ll,string> ans = solve(0,0,0,0,0,0);
        if(ans.second == ""){
            cout << "Answer is : " << ans.first << endl;
        }
        else{
            cout << "Answer is : " << ans.first << " " << ans.second << endl;
        }    
    }
    return 0;
}

