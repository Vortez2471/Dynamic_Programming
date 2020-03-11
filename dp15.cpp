//Egg dropping problem
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
ll ar[ 100 ], n;
ll dp[ 60 ][ 2000 ];
int main()
{
    for ( ll i = 0; i <= 50; i ++)
    {
        for ( ll j = 0; j <= 1000; j ++)
        {
            if ( j == 0 )
                dp[i][j] = 0;
            else if ( i == 0 )
                dp[i][j] = INT_MAX;
            else
            {
                ll ans = INT_MAX;
                for ( ll floor = 1; floor <= j; floor ++)
                    ans = min(ans,max(dp[i-1][floor-1],dp[i][j-floor])+1);
                dp[i][j] = ans;
            }
        }
    }
    ll t;
    cin >> t;
    while ( t-- )
    {
        ll n,b,p;
        cin >> p >> b >> n;
        cout << p <<" " << dp[b][n] <<"\n";
    }
}