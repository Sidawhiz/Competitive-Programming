#include <iostream>
#include <string>
#include <vector>
using namespace std;

//https://codeforces.com/problemset/problem/628/D


/* 
Consider the decimal presentation of an integer. 
Let's call a number d-magic if digit d appears in decimal presentation of the number on even positions 
and nowhere else.

For example, the numbers 1727374, 17, 1 are 7-magic but 77, 7, 123, 34, 71 are not 7-magic. 
On the other hand the number 7 is 0-magic, 123 is 2-magic, 34 is 4-magic and 71 is 1-magic.

Find the number of d-magic numbers in the segment [a, b] that are multiple of m
*/
string s;
int d;
int m;
int dp[12][90][2]; // handles only upto 10 digit numbers, number of times d placed at even place , 
// check for sum divisible by m , last is for tightness check
int solve(int pos ,int sum, int t,int c,int cnt){
    //Base case
    if(pos==s.size()){
        if(sum==0){
            return 1;
        }
        return 0;
    }

    //Check if already stored
    if(dp[pos][sum][t]!=-1){
        return dp[pos][sum][t];
    }
    int ans = 0;
    int lim;
    if(t==1){
        lim = 9;
    }
    else{
        lim = s[pos] - '0';
    }
    for(int i = 0; i<=lim ; i++){
        int ncnt = cnt;
        int r3 = c;
        if(r3==-1 && i!=0){
            r3 = pos;
        }
        else if(r3==-1 && i==0){
            ncnt++;
        }
        int f = t;
        if(f==0 && i<lim){
            f = 1;
        }
        if((pos+ncnt)%2==0 && i==d){
            continue;
        }
        if((pos+ncnt)%2!=0 && i!=d){
            continue;
        }
        ans += solve(pos + 1, (sum * 10 + i) % m, f,r3,ncnt);
    }
    // If not evaluate and store
    dp[pos][sum][t] = ans;
    return dp[pos][sum][t];
}

int main(){
    string a ,b;  // a and b is limit 
    cin >> a >> b;
    int dd , mm; // d-magic and m is divisibility
    cin >> dd >> mm;
    d = dd;
    m = mm;
    int t = a.size() - 1;
    while(a[t]=='0'){
        a[t] = '9';
        t--;
    }
    a[t]--;
    s = a;
    memset(dp, -1 , sizeof(dp));
    int l = solve(0,0,0,-1,0);
    s = b;
    memset(dp, -1,sizeof(dp));
    int r = solve(0,0,0,-1,0);
    cout << "Number of such numbers are : " << r - l<<endl;
    return 0;
}