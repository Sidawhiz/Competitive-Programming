#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

/*
The War of Evil vs Good continues and Ra-One and G-One continue to be on respective sides.
After saving all the cities with Ra-One Numbers G-One realised that some cities 
whose population is a "G-One Number" can be easy target for Ra-One.

A G-One number is a number sum of whose digits is a prime number
For eg. 12 .. sum = 1+2 =3 ... 3 is a prime number.

G-One wants to find out all the populations which can be g-One numbers....
Can You help Him.?
You will be given the range of population and you have to tell him how many in this range are G-One Numbers.
*/

string s;
int dp[12][90][2];

int solve(int pos, int cnt, int t){
    if(pos == s.size()){
        if(cnt==2 || cnt==3 || cnt==5 || cnt==7 || cnt==11|| cnt==13|| cnt==17|| cnt==19|| cnt==23|| cnt==29|| cnt==31|| cnt==37
            || cnt==41|| cnt==43|| cnt==47|| cnt==53|| cnt==59|| cnt==61|| cnt==67|| cnt==71|| cnt==73|| cnt==79|| cnt==83|| cnt==89|| cnt==97){
            return 1;
        }
        return 0;
    }

    if(dp[pos][cnt][t]!=-1){
        return dp[pos][cnt][t];
    }

    int lim;
    if(t==1){
        lim = 9;
    }
    else if(t==0){
        lim = s[pos] - '0';
    }

    int ans = 0;

    for(int i = 0 ; i<=lim ; i++){
        int f = t;
        if(t==0 && i<lim){
            f = 1;
        }
        int ncnt = cnt;
        ncnt = cnt + i;
        ans += solve(pos+1,ncnt,f);
    }
    dp[pos][cnt][t] = ans;
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