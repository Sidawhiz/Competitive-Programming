#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long int ll;

/*
A number is said to be a 369 number if
1. The count of 3s is equal to count of 6s and the count of 6s is equal to count of 9s.
2. The count of 3s is at least 1.

For Example 12369, 383676989, 396 all are 369 numbers whereas 213, 342143, 111 are not.

Given A and B find how many 369 numbers are there in the interval [A, B]. 
Print the answer modulo 1000000007.

Input
The first line contains the number of test cases (T) followed by T lines each containing 2 integers A and B.
Output
For each test case output the number of 369 numbers between A and B inclusive.

Constraints
T<=100                  1<=A<=B<=10^50

Sample Input             Sample Output
3
121 4325                 60
432 4356                 58
4234 4325667             207159

*/
string s;
int dp[55][55][55][55][2];

int solve(int pos, int r3 , int r6 , int r9 , int t){
    //Base case 
    if(pos==s.size()){
        if(r3 > 0){
            if(r3==r6 && r6==r9){
                //cout << "Hello" <<endl;
                return 1;
            }
        }
        return 0;
    }
    //Already stored
    if(dp[pos][r3][r6][r9][t]!=-1){
        return dp[pos][r3][r6][r9][t];
    }

    // If not evaluate
    int ans = 0;
    int f = t;
    int lim = t ? 9 : s[pos] - '0';

    for(int i = 0; i<=lim ; i++){
        i<lim ? f = 1: f=t;
        int a,b,c;
        a = r3; b = r6; c= r9;
        i==3 ? a++ : a =r3;
        i==6 ? b++ : b =r6;
        i==9 ? c++ : c =r9;
        ans+=solve(pos+1,a,b,c,f);
    }

    dp[pos][r3][r6][r9][t] = ans;
    return dp[pos][r3][r6][r9][t];
}

int main(){
    int t;
    string a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        s = a;
        string pearl = ""; 
        memset(dp,-1,sizeof(dp));
        int l = solve(0,0,0,0,0);
        s = b;
        memset(dp,-1,sizeof(dp));
        int r = solve(0,0,0,0,0);
        cout << "Number of such numbers are : " << r-l << endl;
    }
    return 0;
}