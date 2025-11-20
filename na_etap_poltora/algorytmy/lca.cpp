// LCA służy do znajdowanie najbliższego wspólnego przodka
#include <bits/stdc++.h>
using namespace std;
int G[500005];
long long C[500005];
int przodek[500005][20];
vector<pair<int,long long>> sasiedzi[500005];

//DFS
void DFS(int v,int p){

	//Dla każdego wierzchołka ustalamy jego przodków (o 1,2,4,8...)
    przodek[v][0]=p;
    for (int k=1;k<20;k++){
        przodek[v][k]=przodek[przodek[v][k-1]][k-1];
    }
    int u,c;

    //Tworzymy tablice głębokości i ceny od wierzchołka 1
    for (pair<int,int> u_c:sasiedzi[v]){
        u=u_c.first;
        c=u_c.second;
        if (u!=p){
            G[u]=G[v]+1;
            C[u]=C[v]+c;
            DFS(u,v);
        }
    }
}
//LCA - znajdujemy najbliższgo wspólnego przodka
int LCA(int x,int y){
     if (G[y]<G[x]){
        swap(x,y);
     }
     //Sprawiamy, aby x i y były na tej samej głębokości (zmieniamy głębokość y)
     for (int k=19;k>=0;k--){
        if (G[przodek[y][k]]>=G[x]){
            y=przodek[y][k];
        }
        if (x==y) return x;
     }

     //Zmieniamy wysokość x,y aż mają wspolnego ojca
     for (int k=19;k>=0;k--){
        if (przodek[y][k]!=przodek[x][k]){
            y=przodek[y][k];
            x=przodek[x][k];
        }
     }

     // Zwracamy ojca x,y
     return przodek[x][0];
}
