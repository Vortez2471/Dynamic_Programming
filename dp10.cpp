//k-ordered LCS hackerearth
//3D dp
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int n,m,a[2005],b[2005];
int dp[2005][2005][8];
int lcsk(int i,int j,int k)
{
	//memoization
   if(i==n||j==m)
   	return 0;
   if(dp[i][j][k]!=-1)
   	return dp[i][j][k];
   int res=0;
   if(a[i]==b[j])
     res=1+lcsk(i+1,j+1,k);
   else
   {
   	if(k>0)
   	{
       res=1+lcsk(i+1,j+1,k-1);
   	}
   	res=max(res,lcsk(i,j+1,k));
   	res=max(res,lcsk(i+1,j,k));
   }
   return dp[i][j][k]=res;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int k;
	cin>>n>>m>>k;

	int ans=lcsk(n,m,k);
	cout<<ans<<endl;

}