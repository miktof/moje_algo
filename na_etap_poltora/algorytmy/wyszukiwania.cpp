#include <bits/stdc++.h>
using namespace std;
int tab[10]={1,2,2,5,5,8,9,9,12,14};
int UB(int x,int p, int k){
    int s;
    while (k>p){
        s=(p+k+1)/2;
        if (x>=ciag[s]) p=s;
        else k=s-1;
    }
    return p;
}
int LB(int x,int p, int k){
    int s;
    while (k>p){
        s=(p+k)/2;
        if (x<=ciag[s]) k=s;
        else p=s+1;
    }
    return p;
}
int main(){
    cout<<LB(2,10)<<' '<<UB(2,10);
}
