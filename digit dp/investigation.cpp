#include <iostream>
using namespace std;
#include <string>

// For each case, output the case number and the number of integers 
// in the range [A, B] which are divisible by K and the sum of its digits is also divisible by K.

// Each case contains three positive integers A, B and K (1 ≤ A ≤ B < 231 and 0 < K < 10000)

// LightOJ 1068

string s;
int K;
int dp[12][100][100][2]; 
// number of digits max is 10 : for safety 12  
// max sum can be 90 : for safety 100
// sum of sum is next degree
// 2 is for tightness check

int solve(int pos, int sum1, int sum2 , int t){
	//Base Case
	if(pos==s.size()){
		if(sum1==0 && sum2==0){
			return 1;
		}
		return 0;
	}

	if(dp[pos][sum1][sum2][t] != -1){
		return dp[pos][sum1][sum2][t];
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
			f=1;
		}
		int tsum1 = sum1;
		int tsum2 = sum2;
		tsum2 = (i+sum1)%K;
		tsum1 = (sum2*10 + i)%K;
		ans +=solve(pos+1,tsum1,tsum2,f);
	}

	dp[pos][sum1][sum2][t] = ans;
	//cout<<ans<<endl;
	return dp[pos][sum1][sum2][t];
}

int main()
{
	string a, b;
	cin >> a >> b; // input left and right bounds
	int d ;
	cin >> d ; // input K
	K = d;
	int t = a.size() - 1;
	while(a[t]=='0'){
		a[t]='9';
		t--;
	}
	a[t]--; // a converted to a-1;
	s = a;
	memset(dp,-1,sizeof(dp));
	int l = solve(0,0,0,0); // solve for a
	s = b; 
	memset(dp,-1,sizeof(dp));
	int r = solve(0,0,0,0); // solve for b 
	cout << "Number of such numbers are : " << r - l << endl;
	return 0;
}