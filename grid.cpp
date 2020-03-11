//grid problem (minimize the cost)
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int grid_ans(int grid[][100],int n,int m)
{
	int dp[100][100];
	dp[0][0]=grid[0][0];
	for(int i=1;i<n;i++) dp[0][i]=dp[0][i-1]+grid[0][i];
	for(int i=1;i<m;i++) dp[i][0]=dp[i-1][0]+grid[i-1][0];

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
		}
	}
	return dp[n-1][m-1];
}

int main()
{
	int grid[100][100]={{1,2,3},{4,8,2},{1,5,3}};
	cout<<grid_ans(grid,3,3)<<endl;
	return 0;
}