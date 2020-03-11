//fibonacci series
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int dp[1000];
int fibo(int n)
{
//bottom-up dp
dp[0]=0;
dp[1]=1;
for(int i=2;i<=n;i++)
{
dp[i]=dp[i-1]+dp[i-2];
}
return dp[n];
}

int memo[1000];
int memoization(int n)
{
//top-down dp
if(n==0) return 0;
if(n==1) return 1;
if(memo[n]!=-1) return memo[n];
int ans;
ans=memoization(n-1)+memoization(n-2);

return memo[n]=ans;
}

int main()
{
memset(memo,-1,sizeof(memo));
int n;
cin>>n;
cout<<fibo(n)<<"\n"<<memoization(n)<<endl;
}
