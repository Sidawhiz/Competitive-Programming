#include <iostream>
using namespace std;
#include <string>


// THIS QUESTION IS FROM UBER CODING TEST
// Given digits x and y , a positive number M is compact if the number obtained by adding the 
// digits of M can only have x or y has its digits
// example if x=2, y=3 valid sum of compact numbers : 22 , 23 , 33

//find number of "compact" numbers of length exactly n 
// 1 <= n <= 1000

// Sample : Input x , y , n : 1 , 2 , 2
// Output : 18 

string s;
int x ;
int y ;
int n ;
int dp[12][90][2];

int solve(int pos, int sum , int t){
	
	// Base Case
	if(pos == s.size()){
		int pearl = sum;
		string khushi = to_string(pearl);
		string xx = to_string(x);
		char xxx = xx[0];
		string yy = to_string(y);
		string tell = to_string(sum);
		char yyy = yy[0];
		for(int i = 0 ; i < tell.size() ;i++){
			if(khushi[i]!=xxx && khushi[i]!=yyy){
				return 0;
			}
		}
		return 1;
	}

	// If not a base case : check if already evaluated
	if(dp[pos][sum][t]!=-1){
		return dp[pos][sum][t];
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
		int nsum = sum;
		nsum = sum + i ;
		if(t==0 && i<lim){
			f=1;
		}
		ans += solve(pos+1,nsum,f);
	}
	dp[pos][sum][t] = ans;
	return dp[pos][sum][t];
}

int main()
{
	int X,Y,N;

	cin >> X >> Y >> N; // input left and right bounds
	x = X;
	y = Y;
	n = N;
	

	string a ="";
	for(int i = 0 ; i < N-1 ; i++){
		a += '9';
	}
	if(a==""){
		a="0";
	}
	s = a;
	memset(dp,-1,sizeof(dp));
	int l = solve(0,0,0); // solve for a
	//cout  << "Value for a is : "<< l << " , " << s << endl;
	
	n = N+1;
	string b = ""; 
	for(int i = 0 ; i < N ; i++){
		b += '9';
	}
	s=b;
	memset(dp,-1,sizeof(dp));
	int r = solve(0,0,0); // solve for b 
	//cout  << "Value for b is : "<< r << " , " << s << endl;
	//cout << "check" << dp[0][0][0] << endl;

	cout << "Number of such numbers are : " << r - l << endl << r << l;
	return 0;
}