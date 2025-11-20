//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1 << 20;;
int tab[MAXN];
void szybkie(int l,int r){
	if (l>=r) return;
	int i=l-1;
	int j=r+1;
	int wart=tab[l+(rand()%(r-l+1))];
	while (true){
		while (tab[++i]<wart);
		while (tab[--j]>wart);
		if (i<=j){
			swap(tab[i],tab[j]);
		}
		else break;
	}
	if(j > l) szybkie(l,j);
	if(i < r) szybkie(i,r);	
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    cin>>n;
    for (int i=0;i<n;i++) cin>>tab[i];
    szybkie(0,n-1);
    for (int i=0;i<n;i++) cout<<tab[i]<<' ';
}