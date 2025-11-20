//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
int wyn[16000005];
int n,m;
void kmp(string tekst,string wzorzec){
    tekst='$'+wzorzec+'$'+tekst;
    for (int x=0;x<tekst.size();x++) wyn[x]=-1;
    int x;
    for (int i=1;i<tekst.size();i++){
    	x=wyn[i-1];
		while (x>=0 && tekst[i]!=tekst[x+1]){
			x=wyn[x];
		}
		wyn[i]=x+1;
    }
}
void odpowiedz(string tekst){
    int koniec;
    for (int j=0;j<tekst.size();j++){
		koniec=j-2*n;
		if (wyn[j]==n) cout<<koniec<<endl;
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    kmp(b,a);
	odpowiedz('$'+a+'$'+b);

}
