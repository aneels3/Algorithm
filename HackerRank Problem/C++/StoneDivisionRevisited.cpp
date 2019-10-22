#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mod 1000000007
vector<lli> v;
lli n,m;
map<lli,lli > dp;
lli solve(lli val)
 {
  // cout<<val<<" "<<count<<endl;
  
  if(dp[val])
   {  
   return dp[val];
  }
  else
  {
   lli ans=0;
   for(int i=0;i<m;i++)
     {
      if(val%v[i]==0 && val!=v[i])
      {
       ans=max(ans,solve(v[i])*(val/v[i])+1);
      }  
      else if(v[i]>val) break;
      
    }
    dp[val]=ans;
    return ans;
  }
 }

int main()
{
  int q;
  cin>>q;
  while(q--)
  {
    v.clear();
    int sz=dp.size();
    dp.clear();
     cin>>n>>m;
     for(int i=0;i<m;i++)
      {
          lli a;
          cin>>a;
          v.push_back(a);
     }
     sort(v.begin(),v.end());
    cout<<solve(n)<<endl;;
  }
}
