//Grid problem
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<algorithm>

int mincost(int grid[][100],int m,int n)
{
	//complexity is O(n^2)
	int dp[100][100]={};
  
    dp[0][0]=grid[0][0];
    for(int c=0;c<n;c++)  dp[0][c]=dp[0][c-1]+grid[0][c];

    for(int r=1;r<m;r++)
    	dp[r][0]=dp[0][r-1]+grid[r][0];

    for(int r=1;r<m;r++)
    {
    	for(int c=1;c<n;c++)
    		dp[r][c]=min(dp[r-1][c],dp[r][c-1])+grid[r][c];
    }
    return dp[m-1][n-1];

}

int main()
{
	int grid[100][100]={{1,2,3},{4,8,2},{1,5,3}};

	int ans=mincost(grid,3,3);
	cout<<ans<<endl;
}