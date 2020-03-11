//Fibonacci number
#include<iostream>
using namespace std;

/*int fib(int n)
{
    
    //complexity is O(2^n) by recursion

	if(n==1)
		return 1;
	if(n==0)
	    return 0;
	int ans=fib(n-1)+fib(n-2);
	return ans; 
}
int main()
{
	int n;
	cin>>n;
	int ans=fib(n);

	cout<<ans<<endl;
}*/

//DP is of two types memoization(top-down dp) and bottom up(pure dp)
//memoization fails sometimes

int memo[1000];
int fib(int n)
{
    
    //complexity is O(n) by memoization

	if(n==1)
		return 1;
	if(n==0)
	    return 0;
	if(memo[n]!=-1)
		return memo[n];

	int ans=fib(n-1)+fib(n-2);
	memo[n]=ans;
	return ans; 
}
int main()
{
	int n;
	cin>>n;

	for(int i=0;i<1000;i++)
		memo[i]=-1;

	int ans=fib(n);

	cout<<ans<<endl;
}

