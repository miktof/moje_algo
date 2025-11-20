#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,l;
    cin>>n>>k;
    vector<int> nominaly;
    for (int x=0;x<n;x++){
        cin>>l;
        nominaly.push_back(l);
    }
    int inf=1000005;
    int dp[k+1];
    dp[0]=0;
    for (int y=1;y<=k;y++) dp[y]=inf;
    for (int nom:nominaly){
        for (int kwota=nom;kwota<=k;kwota++){
            dp[kwota]=min(dp[kwota],dp[kwota-nom]+1);
        }
    }
    if (dp[k]==inf) cout<<"NIE";
    else cout<<dp[k];
}
