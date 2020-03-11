//mixtures spoj
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int arr[1000];
long long dp[1000][1000];

long long sum(int i,int j)
{
  	long long ans=0;
    for(int k=i;k<=j;k++)  
    {
    	ans=ans+arr[i];
    	ans=ans%100;
    }
    return ans;
}

long long solvemixtures(int i,int j)
{
   if(i>=j)
   	return 0;
   if(dp[i][j]!=-1)
   	return dp[i][j];
   
   dp[i][j]=INT_MAX;
   for(int k=i;k<=j;k++)
   {
     dp[i][j]=min(dp[i][j],(solvemixtures(i,k)+solvemixtures(k+1,j)+sum(i,k)*sum(k+1,j)));
   }
   return dp[i][j];
}

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
           cin>>arr[i];
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=-1;
			 
		cout<<solvemixtures(0,n-1)<<endl;
	}
}