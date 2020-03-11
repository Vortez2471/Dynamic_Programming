//Rod cutting to maximize profit
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int maxprofit(int arr[],int len)
{
	//complexity is O(4^n)
	if(len==0) return 0;
    int best=0;
	for(int i=1;i<=len;i++)
	{
		int netprofit=arr[i]+maxprofit(arr,len-i);
		best=max(best,netprofit);
	}

	return best;
  
}

int memo[100];
int memoization(int arr[],int len)
{
	//complexity is O(n^2)
	if(len==0) return 0;

    if(memo[len]!=-1) return memo[len];

    int best=0;
	for(int i=1;i<=len;i++)
	{
		int netprofit=arr[i]+maxprofit(arr,len-i);
		best=max(best,netprofit);
	}
    memo[len]=best;
	return best;

}

int bottom_to_up(int arr[],int len)
{
	//complexity is O(n^2)
	int dp[100]={};

	for(int clen=1;clen<=len;clen++)
	{
		int best=0;
		for(int cut=1;cut<=clen;cut++)
		{
			best=max(best,arr[cut]+dp[clen-cut]);
		}
		dp[clen]=best;
	}
	return dp[len];
}

int main()
{
	int price[100];
	int totallen;
	cin>>totallen;

	for(int i=1;i<=totallen;i++)
	{
		cin>>price[i];
	}

    for(int i=0;i<=totallen;i++)
    {
    	memo[i]=-1;
    }

	int ans=maxprofit(price,totallen);
    cout<<ans<<"\n"<<memoization(price,totallen)<<"\n"<<bottom_to_up(price,totallen)<<endl;

}