//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1e6+7;
vector<int> graf[MAXN];
int rozmiar[MAXN];
bool byl_centroidem[MAXN];
bool odw[MAXN];
vector<int> centroidy;
int n;
void wczytanie(){
    cin>>n;
    int a,b;
    for (int i=0;i<n-1;i++){
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
}
void DFS_rozmiar(int v,int oj){
    rozmiar[v]=1;
    for (int u:graf[v]){
        if (u!=oj && byl_centroidem[u]==0){
            DFS_rozmiar(u,v);
            rozmiar[v]+=rozmiar[u];
        }
    }
}
int znajdz_centroid(int v,int oj,int wielkosc){
    for (int u:graf[v]){
        if (u!=oj && byl_centroidem[u]==0 && rozmiar[u]>(wielkosc/2)){
            return znajdz_centroid(u,v,wielkosc);
        }
    }
    return v;
}

void dekcen(int v){
    //obliczanie rozmiarów
    DFS_rozmiar(v,0);
    // szukanie centroida
    int c=znajdz_centroid(v,0,rozmiar[v]);
    byl_centroidem[c]=1;
    centroidy.push_back(c);
    // wywolanie sie dla synów
    for (int u:graf[c]){
        if (byl_centroidem[u]==0) dekcen(u);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    wczytanie();
    dekcen(1);
    for (int i=0;i<centroidy.size();i++) cout<<centroidy[i]<<' ';
}
