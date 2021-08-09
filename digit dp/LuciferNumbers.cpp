#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


/*
Lucifer is the only human whi has defeated RA-ONE in a computer game ..
RA-One is after lucifer for revenge and G-One is there to protect him ...
All thi G-One and Ra-one Nonsense has disturbed lucifers life..

He wants to get Rid of Ra-One and kill him . 
He found that Ra-One can be killed only by throwing Lucifer number of weapons at him.

Lucifer number  shares the some properties of Ra-One Numbers numbers and G-One Numbers

Any number is LUCIFER NUMBER  if
the Difference between Sum of digits at even location and Sum of digits at odd location is prime number .. 
For eg... for 20314210 is lucifer number

digits at odd location 0,2,1,0
digits at even location 1,4,3,2
diff = (1+4+3+2)-(0+2+1+0)=10-3  = 7 ..... a prime number.

Lucifer has access to a Warehouse which has lots of weapons ..
He wants to know in how many ways can he kill him.
Can you help him?

NOTE: t will be less than 100
from and to will be between 0 and 10^9 inclusive 
*/
string s;
int dp[12][90][2];
vector<int> v;
string p2;
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

    int vick = v[pos];
    for(int i = 0 ; i<=lim ; i++){
        int f = t;
        if(t==0 && i<lim){
            f = 1;
        }
        int ncnt = cnt;
        ncnt = cnt + i*vick ;
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
    int si = a.size();
    vector<int> ll;
    int ii = 1;
    while(si){
        ii = -ii;
        ll.insert(ll.begin(),ii);
        si--;
    }
    v = ll;
    memset(dp,-1,sizeof(dp));
    int l = solve(0,0,0); // solve for a
    s = b; 
    int si2 = b.size();
    ll.clear();
    int ii2 = 1;
    while(si2){
        ii2 = -ii2;
        ll.insert(ll.begin(),ii2);
        si2--;
    }
    v = ll;
    memset(dp,-1,sizeof(dp));
    int r = solve(0,0,0); // solve for b 

    cout << "Number of such numbers are : " << r - l<<endl;
    return 0;
}