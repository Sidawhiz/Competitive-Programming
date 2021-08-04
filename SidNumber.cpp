#include <iostream>
using namespace std;
#include <string>

// x is a number in range a to b where digit d occurs exactly k times in x
// 1 <= a <= b <= 10^11

string s;
int digit;
int inter;
int dp[12][12][2];  

// first 12 corresponds to number of digits we are considering  10^11 has 12 digits in it
// last 2 is just for tightness check -: 1 is number already less than given number - : 0 number is still not less
//middle 12 - :  Let x be anumber we're considering between a and b. Let G(x) be a function that count number of times 
			   // d is present in x . Let x = 33,333,333,333 d = 3 , hence G(x) = 11 Hence, columns = 12
// while constructing number x = 33,343,_ _ _,_ _ _ while constructing this dp[5][4][0 or 1]
// dp[pos][cnt][tight]

int solve(int pos , int cnt , int t){
	// Base case :
	if(cnt>inter){
		return 0;
	}
	if(pos == s.size()){
		if(cnt == inter){
			return 1;
		}
		return 0;
	}

	// If not a base case : check if already evaluated

	if(dp[pos][cnt][t] != -1){
		return dp[pos][cnt][t];
	}

	// If already not evaluated , evaluate and store

	int lim;
	if(t==1){
		lim = 9;
	}
	else if(t==0){
		lim = s[pos] - '0';
	}

	int ans = 0;
	for(int i = 0 ; i <= lim ; i++){
		int f = t;
		int ncnt = cnt;
		if(i==digit){
			ncnt++;
		}
		if(t==0 && i<lim){
			f=1;
		}
		ans+=solve(pos+1,ncnt,f);
	}
	dp[pos][cnt][t] = ans;
	//cout<<ans<<endl;
	return dp[pos][cnt][t];
}

int main()
{
	string a, b;
	cin >> a >> b; // input left and right bounds
	int d ;
	int k ;
	cin >> d >> k; // input digit and k times
	digit = d;
	inter = k;
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