//Wine problem 
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int memo[1000][1000];
int wine(int arr[],int s,int e,int year)
{
	if(s>e)
		return 0;
	if(memo[s][e]!=-1)
		return memo[s][e];
	int q1=INT_MIN;
	int q2=q1;

	q1=arr[s]*year+wine(arr,s+1,e,year+1);
	q2=arr[e]*year+wine(arr,s,e-1,year+1);

	int ans=max(q1,q2);

	return memo[s][e]=ans;

}

int bottom_up(int arr[],int n)
{
	int dp[1000][1000];
	int year=n;
	for(int i=0;i<=n;i++)
		dp[i][i]=arr[i]*year;
	year--;
	for(int len=2;len<=n;len++)
	{
		int s=0;
		int e=n-len;
		while(s<=e)
		{
			int end=s+len-1;
			dp[s][end]=max(arr[s]*year+dp[s+1][end],arr[end]*year+dp[s][end-1]);
			s++;
		}
		year--;
	}
	return dp[0][n-1];
}

int main()
{
	memset(memo,-1,sizeof(memo));
	int n;
	cin>>n;
	int arr[n];
	arr[0]=INT_MAX;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<wine(arr,0,n-1,1)<<"\n"<<bottom_up(arr,n)<<endl;
}