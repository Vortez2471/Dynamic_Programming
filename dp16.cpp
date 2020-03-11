//Valentine magic hacker block
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
ll n,m,arr[5005],brr[5005],dp[5005][5005];
ll f(ll i,ll j)
{
	//complexity is O(n^2)
	if(i==n)
		return 0;
	if(j==m)
		return INT_MAX;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int op1=abs(arr[i]-brr[j]+f(i+1,j+1));
	int op2=f(i,j+1);

	return dp[i][j]=min(op1,op2);
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<m;i++)
		cin>>brr[i];
	sort(arr,arr+n);
	sort(brr,brr+m);

	ll ans=f(0,0);
	cout<<ans<<endl;
	return 0;
}