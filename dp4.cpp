//Wine problem (to make max profit)
//2D DP
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<algorithm>

int maxprofit(int arr[], int be,int en,int year)
{
	//complexity is O(2^n) by recursion
   if(be>en) return 0;

   int q1=arr[be]*year+maxprofit(arr,be+1,en,year+1);
   int q2=arr[en]*year+maxprofit(arr,be,en-1,year+1);
   int ans=max(q1,q2);
   return ans;
}

int memo[100][100];
int memoization(int arr[], int be,int en,int year)
{
	//complexity is O(n^2) by memoization
   if(be>en) return 0;
   if(memo[be][en]!=-1) return memo[be][en];
   int q1=arr[be]*year+memoization(arr,be+1,en,year+1);
   int q2=arr[en]*year+memoization(arr,be,en-1,year+1);
   int ans=max(q1,q2);
   memo[be][en]=ans;
   return ans;
}

int bottom_to_up(int arr[], int n)
{
   int dp[100][100]={};
   int year=n;
   for(int i=0;i<n;i++)
   {
   	dp[i][i]=year*arr[i];
   }
   --year;
   for(int len=2;len<=n;len++)
   {
   	int srt=0;
   	int end=n-len ;
   	while(srt<=end)
   	{
   		int endwindow=srt+len-1;
   		dp[srt][endwindow]=max(arr[srt]*year+dp[srt+1][endwindow],
   			arr[endwindow]*year+dp[srt][endwindow-1]);
   		srt++;
   	}
   	--year;
   }
   return dp[0][n-1];
}

int main()
{
  int arr[100];
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
  	cin>>arr[i];
  }
  memset(memo,-1,sizeof(memo));
  int ans1=maxprofit(arr,0,n-1,1);
  int ans2=memoization(arr,0,n-1,1);
  cout<<ans1<<"\n"<<ans2<<"\n"<<bottom_to_up(arr,n)<<endl;
}


