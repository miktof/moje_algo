//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1 << 20;;
int tab[MAXN];

void babelkowe(int n){
    int zmian=1;
    while (zmian!=0){
        zmian=0;
        for (int i=0;i<n-1;i++){
            if (tab[i]>tab[i+1]){
                swap(tab[i],tab[i+1]);
                zmian++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    cin>>n;
    for (int i=0;i<n;i++) cin>>tab[i];
    babelkowe(n);
    for (int i=0;i<n;i++) cout<<tab[i]<<' ';
}