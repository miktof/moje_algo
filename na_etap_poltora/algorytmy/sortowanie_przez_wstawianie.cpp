//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1 << 20;;
int nieposortowane[MAXN];
int posortowane[MAXN];

void wstawianie(int n){
    int el,j,pom;
    int i=0;
    while (i<n){
        el=nieposortowane[i];
        j=0;
        while (j<i){
            if (posortowane[j]>=el) break;
            j++;
        }
        while (j<=i){
            pom=posortowane[j];
            posortowane[j]=el;
            el=pom;
            j++;
        }
        i++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    cin>>n;
    for (int i=0;i<n;i++) cin>>nieposortowane[i];
    wstawianie(n);
    for (int i=0;i<n;i++) cout<<posortowane[i]<<' ';
}