#include <iostream>
using namespace std;
#include <bits/stdc++.h>
/*
Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring
some cost thatmay vary depending on work job assignment. It is required to perform all jobs
by assigning exactly one worker to each job and exactly one job to each agent in such a way
that total cost of assignment is minimized.

Input Format : Number of workers and jobs : N
Cost matrix C with dimension N*N where C(i,j) is cost for ith person doing jth job

4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
*/

vector< vector<int> > C;
int dp[21][1<<21]; // assign people to jobs or assign jobs to people . I'll work with former.
int solve(int t , int mask, int n){ // t signifies job number and mask signifies available people
    //Base Case
    if(t==n){
        return 0;
    }

    if(dp[t][mask]!=-1){
        return dp[t][mask];
    }

    int ans = INT_MAX;

    for(int j = 0 ; j < n ; j++){
        if((mask & (1<<j))!=0){
            ans = min(ans, C[j][t] + solve(t+1,(mask ^ (1<<j)),n));
        }
    }
    dp[t][mask] = ans;
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int a;
    int t;
    cin >> t;
    int k = t;
    int tt = t;
    vector< vector<int> > c;
    memset(dp,-1,sizeof(dp));
    while(tt--){
        vector<int> l;
        while(k--){
            cin >> a;
            l.push_back(a);
        }
        c.push_back(l);
        k = t;
    }
    C = c;
    int d = solve(0,(1<<t)-1,t) ;
    cout << d << endl;
    return 0;
}
