//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1 << 20;
int tab[MAXN];

void scalanie (int l1, int r1, int l2, int r2){
    int pocz=l1;
    int kon=r2;
    if (l1<r1) scalanie(l1,(l1+r1)/2,(l1+r1)/2+1,r1);
    if (l2<r2) scalanie(l2,(l2+r2)/2,(l2+r2)/2+1,r2);
    vector<int> v;
    while (l1<=r1 && l2<=r2){
        if (tab[l1]<=tab[l2]){
            v.push_back(tab[l1]);
            l1++;
        }
        else{
            v.push_back(tab[l2]);
            l2++;
        }
    }
    while (l1<=r1){
        v.push_back(tab[l1]);
        l1++;
    }
    while (l2<=r2){
        v.push_back(tab[l2]);
        l2++;
    }
    for (int i=pocz;i<=kon;i++){
        tab[i]=v[i-pocz];
    }
}
void fastscan(int &number) {
    bool negative = false;
    register char c;
    number = 0;
    c = getchar();
    if (c=='-'){
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    fastscan(n);
    for (int i=0;i<n;i++) fastscan(tab[i]);
    scalanie(0,n/2-1,n/2,n-1);
    for (int i=0;i<n;i++) cout<<tab[i]<<' ';
}
