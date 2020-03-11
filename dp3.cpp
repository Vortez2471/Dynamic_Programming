//Minimum step to reduce to 1 any number to be reduced to 1 in minimum steps
#include<iostream>
using namespace std;
#include<algorithm>
//division by 3 or by 2 or substraction by -1


/*
//WRONG APPROACH
int steps=0;
int reduce(int n)
{
	if(n==1)
		return steps;
	if(n%3==0)
	{
		steps++;
		return reduce(n/3);
	}
	if(n%2==0)
	{
		steps++;
		return reduce(n/2);
	}
	else
	{
		steps++;
		return reduce(n-1);
	}
}
*/

/*const int inf=(int)1e9;

int reduce(int n)
{
	//complexity is O(3^n) by recursion
	if(n==1) return 0;

	int q1=inf,q2=inf,q3=inf;

	if(n%3==0) q1=1+reduce(n/3);
	if(n%2==0) q2=1+reduce(n/2);
	q3=1+reduce(n-1);

	return min(q1,min(q2,q3));
}

 int main()
 {
 	int n;
 	cin>>n;

 	int ans=reduce(n);

 	cout<<ans<<endl;
 }
*/

/*int memo[10000];
const int inf=(int)1e9;

int reduce(int n)
{
	//complexity is O(n) by memoized solution
	if(n==1) return 0;

	int q1=inf,q2=inf,q3=inf;
 
    if(memo[n]!=-1) return memo[n];

	if(n%3==0) q1=1+reduce(n/3);
	if(n%2==0) q2=1+reduce(n/2);
	q3=1+reduce(n-1);

    memo[n]= min(q1,min(q2,q3));

	return min(q1,min(q2,q3));
}

 int main()
 {
 	int n;
 	cin>>n;
    fill(memo,memo+n+1,-1);
 	int ans=reduce(n);

 	cout<<ans<<endl;
 }
 */

const int inf=(int)1e9;
int reduce(int n)
{
    
    //complexity is O(n) by DP

	int dp[1000];

	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
    
    for(int curnum=4;curnum<=n;curnum++)
    {
    	int q1=inf,q2=inf,q3=inf;

    	if(curnum%3==0) q1=1+dp[curnum/3];
    	if(curnum%2==0) q2=1+dp[curnum/2];
    	q3=1+dp[curnum-1];
    	dp[curnum]=min(q1,min(q2,q3));
    }

    return dp[n];

}

 int main()
 {
 	int n;
 	cin>>n;
  
 	int ans=reduce(n);

 	cout<<ans<<endl;
 }