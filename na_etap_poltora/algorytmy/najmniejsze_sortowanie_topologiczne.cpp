//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1<<17;
vector<int> graf[MAXN];
priority_queue<int> zera;
vector<int> wynik;
int ile[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        graf[a].push_back(b);
        ile[b]++;
    }
    for (int i=1;i<=n;i++){
        if (ile[i]==0) zera.push(-i);
    }
    int v;
    while (zera.size()>0){
        v=zera.top();
        v=v*-1;
        wynik.push_back(v);
        zera.pop();
        for (int u: graf[v]){
            if (ile[u]!=0){
                ile[u]-=1;
                if (ile[u]==0) zera.push(-u);
            }
        }
    }
    if (wynik.size()==n){
        cout<<"TAK ";
        for (int w:wynik) cout<<w<<' ';
    }
    else{
        cout<<"NIE";
    }
}
