#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long int ll;

/*
Charles, Laura and Logan have been staying in a hotel in Oklahoma City. 
The Reavers catched up with them, but Charles suffers a seizure and telepathically freezes everyone in the hotel

Logan must inject Charles with a suppressant. 
However, to counter this freezing effect, he must find the DIGIT IMMUNE numbers as soon as possible.

A Digit-Immune number is a number which is not divisible by any of its digits. 
For example: 23,27,37 etc.

Now, there also exists an additional condition to these type of numbers.

A digit-immune number will be called an odd-digit-immune number if it contains only odd digits.
He has to tackle certain queries.

In a single query, Logan is given two integers A and B. 
He has to find Kth odd digit-immune number between A and B (both inclusive).

************ Note - Below code counts number of odd-digit-immune numbers in the given range ***********

1 ≤ A ≤ B ≤ 10^18                1 ≤ K ≤ 1018
*/
string s;
vector<bool> check(4,false);
vector<int> num;
int dp[20][20][20][20][20][2]; // number of digits, for 3, for 5 , for 3 , for 9;

int solve(int pos, int r3, int r5, int r7, int r9, int c3, int c5, int c7, int c9, int t, int zero){
    if(pos==s.size()){
        int b,c,d,e;
        if(c3==0){
            b = 1;
        }
        else{
            b = r3;
        }
        if(c5==0){
            c = 1;
        }
        else{
            c = r5;
        }
        if(c7==0){
            d = 1;
        }
        else{
            d = r7;
        }
        if(c9==0){
            e = 1;
        }
        else{
            e = r9;
        }
        if(b!=0 && c!=0 && d!=0 && e!=0){
            //cout << pearl << " ";
            return 1;
        }
        return 0;
    }

    if(dp[pos][r3][r5][r7][r9][t]!=-1){
        return dp[pos][r3][r5][r7][r9][t];
    }

    int lim;
    int ans = 0;
    lim = t ? 9 : s[pos] -'0';
    int f = t;
    for(int i = 0; i <=lim ; i++){
        if(i < lim){
            f = 1;
        }
        else{f=t;}
        if(zero!=-1 && i==0){
            continue;
        }
        if(i==2 || i==4 || i==1 || i==6 || i==8){
            continue;
        }
        //pearl +=to_string(i)[0];
        int l,m,n,o,zero2,p,q,r,s;
        if(i!=0){
            zero2 = 0;
        }
        else if(i==0){
            zero2=-1;
        }
        if(i==3){
            p = 1;
        }
        else{
            p = c3;
        }
        if(i==5){
            q = 1;
        }
        else{
            q = c5;
        }
        if(i==7){
            r = 1;
        }
        else{
            r = c7;
        }
        if(i==9){
            s = 1;
        }
        else{
            s = c9;
        }
        l = (10*r3 + i)%3;
        m = (10*r5 + i)%5;
        n = (10*r7 + i)%7;
        o = (10*r9 + i)%9;
        ans += solve(pos+1,l,m,n,o,p,q,r,s,f,zero2);
        //pearl.pop_back();
    }
    dp[pos][r3][r5][r7][r9][t] = ans;
    return dp[pos][r3][r5][r7][r9][t];
}

int main(){
    int A,B,K;
    cin >> A >> B;

    //k = K;
    memset(dp,-1,sizeof(dp));
    s = to_string(A);
    string pearl = "";
    int l = solve(0,0,0,0,0,0,0,0,0,0,-1);
    //cout << "------------------------" << endl;
    memset(dp,-1,sizeof(dp));
    s = to_string(B);
    pearl = "";
    int r = solve(0,0,0,0,0,0,0,0,0,0,-1);

    cout << "Number of such numbers : " << r - l << endl;
    return 0;
}

