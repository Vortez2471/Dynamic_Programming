//Reducing a number to 1
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int memo[1000];
int reduce(int n)
{
	if(n==1)
		return 0;
	if(memo[n]!=-1)
		return memo[n];
	int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
	if(n%2==0)
		q1=1+reduce(n/2);
	if(n%3==0)
		q2=1+reduce(n/3);
	else
		q3=1+reduce(n-1);
	int ans=min(q1,min(q2,q3));

	return memo[n]=ans;
    
}

int inf=(int)1e9;
int reduce_dp(int n)
{
	int dp[1000];
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	for(int i=4;i<=n;i++)
	{
		int q1=inf,q2=inf,q3=inf;
		
		if(i%2==0) q1=1+dp[i/2];
		if(i%3==0) q2=1+dp[i/3];
		else q3=1+dp[i-1];
		
		dp[i]=min(q1,min(q2,q3));
	}
	
	return dp[n];
}

int main()
{
	memset(memo,-1,sizeof(memo));
	int n;
	cin>>n;
	cout<<reduce(n)<<"\n"<<reduce_dp(n)<<endl;
}