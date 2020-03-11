//Bottom-up approach of fibonacci
#include<iostream>
using namespace std;
//1 sec->10^8 instruction is processed by computer

int fib(int n)
{

    //Complexity is O(n) by bottom-up dp

	int dp[1000]={};

	dp[0]=0;
	dp[1]=1;

	for(int curnum=2;curnum<=n;curnum++)
		dp[curnum]=dp[curnum-1]+dp[curnum-2];

	return dp[n];

}

int main()
{
	int n;
	cin>>n;
	int ans=fib(n);
	cout<<ans<<endl;
}
