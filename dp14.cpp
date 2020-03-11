//ShopTrip codechef
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
double x[40],y[40];
int msk[40];
double dp[5000][40];
int n,m;
 
double dist(int i, int j){
    return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}
 
double fun(int ing,int sh){
    if(ing+1==(1<<m))return dist(sh,0);
    if(dp[ing][sh]!=-1)return dp[ing][sh];
    
    
    double res;
    
    for(int i=1;i<=n;i++){
        if(i == sh || (msk[i] | ing)==ing)continue;
        
        res=fun(ing | msk[i],i)+dist(sh, i);//sqrt(pow(x[sh]-x[i],2)+pow(y[sh]-y[i],2));
        if(dp[ing][sh]==-1 || dp[ing][sh]>res)dp[ing][sh]=res;
        
    }
   return dp[ing][sh];
    
}
 
int main(){
    
    int t;
    cin>>t;
    while(t--){
        
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        memset(msk,0,sizeof msk);
        for(int i=0;i<5000;i++)for(int j=0;j<40;j++)dp[i][j]=-1;
        
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
        }
        
        
        bool f[m];
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            reverse(s.begin(), s.end());
            for(int j = 0; j< m; j++)if(s[j] == '1'){msk[i] = msk[i]|(1<<j); f[j] = 1;}
        }
        
      //  for(int i=1;i<=n;i++)cout<<msk[i]<<endl;
        
        int fl=0;
        for(int i=0;i<m;i++)if(f[i]==0)fl=1;
        
        if(fl==1)cout<<"-1\n";
        
        else printf("%.10f\n",fun(0,0));
        
        }
         
    return 0;
}  