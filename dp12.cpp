//Diwali problem hacker blocks
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 1000003
long n,x;
long dp[105][3][105];
long f(long i,long prev,long cnt)
{
	if(i==n)
	{
		if(cnt==x)
			return 1;
		return 0;
	}
	if(dp[i][prev][cnt]!=-1)
		return dp[i][prev][cnt];
	long ans=0;

	if(prev==1)
		ans=ans+f(i+1,1,cnt+1);
	else
	{
		ans=ans+f(i+1,1,cnt)
	}
	ans=ans%mod;

    ans=ans+f(i+1,0,cnt);
    ans=ans%mod;

    return dp[i][prev][cnt]=ans;
}
int main()
{
	long t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>n>>x;
		cout<<(f(1,0,0)+f(1,1,0))%mod<<endl;
	}
	return 0;
}