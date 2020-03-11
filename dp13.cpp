//Travelling salesman problem
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n=4;
int dp[16][4];
int dist[10][10]={
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};

int visited=(1<<n)-1;
int tsp(int mask,int pos)
{
	if(mask==visited)
		return dist[pos][0];
	if(dp[mask][pos]!=-1)
		return dp[mask][pos];
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		//i is city
		if((mask&(1<<i))==0)
		{
			int newans=dist[pos][i]+tsp(mask|(1<<i),i);
			ans=min(ans,newans);
		}
	}
	return dp[mask][pos]=ans;
}
int main()
{
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			dp[i][j]=-1;

   cout<<tsp(1,0)<<endl;
}