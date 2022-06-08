#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define push_back pb

//const int N = 1000;
// const int mod = 1e9+7;
const int N = 1000;

// tells if it is possible to have change

string a;
pair<int,int> dp[N][N]; // number of ways or count of 0 and 1 respectively

pair<int,int> solve(int i, int j){

    //Already evaluated
    if(dp[i][j]!=make_pair(-1,-1)){
        return dp[i][j];
    }

    //Base Case
    if(i==j){
        if(a[i]=='0'){
            return dp[i][j]=make_pair(1,0);
        }
        return dp[i][j]=make_pair(0,1);
    }
    if(j==i+2){
        int f = -1;
        if(a[i+1]=='^'){
            f = (a[i]-'0') ^ (a[j]-'0');
        }
        else if(a[i+1]=='|'){
            f = (a[i]-'0') | (a[j]-'0');
        }
        else if(a[i+1]=='&'){
            f = (a[i]-'0') & (a[j]-'0');
            //cout << "Hi " << f << endl; 
        }
        if(f==0){
            return dp[i][j]=make_pair(1,0);
        }
        else if(f==1){
            return dp[i][j]=make_pair(0,1);
        }
    }

    //Else evaluate
    pair<int, int> ans = make_pair(0,0);

    for(int k = i; k<j ; k=k+2){
        if(a[k+1]=='|'){
            ans.first += solve(i,k).first*solve(k+2,j).first;
            ans.second += solve(i,k).second*solve(k+2,j).first + solve(i,k).first*solve(k+2,j).second + solve(i,k).second*solve(k+2,j).second;
        }
        else if(a[k+1]=='&'){
            ans.second += solve(i,k).second*solve(k+2,j).second;
            ans.first += solve(i,k).second*solve(k+2,j).first + solve(i,k).first*solve(k+2,j).second + solve(i,k).first*solve(k+2,j).first;
        }
        else if(a[k+1]=='^'){
            ans.first += solve(i,k).first*solve(k+2,j).first + solve(i,k).second*solve(k+2,j).second;
            ans.second += solve(i,k).first*solve(k+2,j).second + solve(i,k).second*solve(k+2,j).first;
        }
    }
    // cout << ans.first << " " << ans.second << endl;
    // cout << i << " i,j " << j << endl;
    return dp[i][j] = ans;
}

int main(){

    int n;
    cin >> n;
    string temp;
    cin >> temp;

    for(int i = 0; i<2*n-1 ; i++){
        if(temp[i]=='T'){
            temp[i] = '1';
        }
        else if(temp[i]=='F'){
            temp[i] = '0';
        }
    }

    a = temp;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N ; j++){
            dp[i][j] = make_pair(-1,-1);
        }
    }

    cout << solve(0,2*n-2   ).second << endl;

}
