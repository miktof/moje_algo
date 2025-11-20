//Szybkie potęgowanie
#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long pot(long long a,long long p){
	if (p==0) return 1;
	if (p%2==1){
		return (a*pot(a,p-1))%mod;
	}
	long long pom=pot(a,p/2);
	return (pom*pom)%mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout<<pot(31,1000000);
}
