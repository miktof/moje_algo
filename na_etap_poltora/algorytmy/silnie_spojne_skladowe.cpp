//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1002137;
vector<int> graf[MAXN];
vector<int> graf2[MAXN];
vector<int> graf_spojnych[MAXN];
int spojna[MAXN];
stack<int> post_order;
bool odw[MAXN];
int n,m;
void wczytanie(){
    cin>>n>>m;
    int a,b;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        graf[a].push_back(b);
        graf2[b].push_back(a);
    }
}
void DFS_post(int v){
    odw[v]=1;
    for (int u:graf[v]){
        if (odw[u]==0) DFS_post(u);
    }
    post_order.push(v);
}
void DFS(int v,int s){
    spojna[v]=s;
    for (int u:graf2[v]){
        if (spojna[u]==0) DFS(u,s);
    }
}
void podziel_na_spojne(){
    for (int i=1;i<=n;i++){
        if (odw[i]==0) DFS_post(i);
    }
    for (int i=1;i<=n;i++) odw[i]=0;
    int v;
    while (post_order.size()>0){
        v=post_order.top();
        post_order.pop();
        if (spojna[v]==0) DFS(v,v);
    }
}
void DFS_spojne(int v){
    odw[v]=1;
    for (int u:graf[v]){
        if (spojna[u]!=spojna[v]){
            graf_spojnych[spojna[v]].push_back(spojna[u]);
        }
        if (odw[u]==0) DFS_spojne(u);
    }
}
void stworz_graf_spojnych(){
    for (int i=1;i<=n;i++){
        if (odw[i]==0){
            DFS_spojne(i);
        }
    }
}
int main(){
    wczytanie();
    podziel_na_spojne();
    for (int i=1;i<=n;i++){
        cout<<i<<' '<<spojna[i]<<endl;
    }
    cout<<endl;
    stworz_graf_spojnych();
    for (int i=1;i<=n;i++){
        if (spojna[i]!=i) continue;
        cout<<i<<":   ";
        for (int u:graf_spojnych[i]) cout<<u<<' ';
        cout<<endl;
    }
}
