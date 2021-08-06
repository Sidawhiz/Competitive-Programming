#include <iostream>
using namespace std;
#include <string>
#include <vector>
/* 
In the War between good and evil . Ra-One is on the evil side and G-One on the good side.

Ra-One is fond of destroying cities and its G-one's duty to protect them..

Ra-One loves to destroy cities whose Zip Code has special properties. 
He says he loves to destroy cities which have Ra-One numbers as their ZIp Code.

Any number is Ra-one if the Difference between Sum of digits at even location and Sum of digits at odd location is One (1).. 
For eg... for 234563 is Ra-One number

digits at odd location are 3,5,3 (unit place is location 1 )

digits at even location are 2,4,6

Diff = (2+4+6)-(3+5+3)=12-11 = 1.

And 123456 is not Ra-One number

diff = (5+3+1) - (2+4+6) = -3

G-One knows this about Ra-one and wants to deploy his Army members in those cities. 
1 army member will be deployed in each city.

G-one knows the range of ZIP-Codes where Ra-One might attack & 
needs your help to find out how many army members he needs.

Can you help Him ?
*/
string s;
int dp[12][90][2];
vector<int> v;
string p2;
int solve(int pos, int cnt, int t){
	if(pos == s.size()){
		if(cnt==1){
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