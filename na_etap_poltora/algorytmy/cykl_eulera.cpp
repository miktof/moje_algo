//Cykl eulera - ka¿d¹ krawêdŸ przechodzi raz.
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int MAXN=300007;
int ile[MAXN];
vector<pair<int,int>> graf[MAXN];
int spojna[MAXN];
int rozmiar_spojnej[MAXN];
bool odw[MAXN];
vector<int> wynik;
int n,m;
int nr_spojnej=0,ile_spojnych=0;
void wczytanie(){
    cin>>n>>m;
    int a,b;
    for (int i=0;i<m;i++){
        cin>>a>>b;
        ile[a]++;ile[b]++;
        graf[a].push_back({b,i});
        graf[b].push_back({a,i});
    }
}
void DFS(int v,int s){
    spojna[v]=s;
    rozmiar_spojnej[s]++;
    for (pair<int,int> u:graf[v]){
        if (spojna[u.first]==0) DFS(u.first,s);
    }
}
bool czy(){
    for (int i=1;i<=n;i++){
        if (spojna[i]==0){
            nr_spojnej++;
            DFS(i,nr_spojnej);
        }
    }
    for (int i=1;i<=nr_spojnej;i++){
        if (rozmiar_spojnej[i]>1) ile_spojnych++;
    }
    if (ile_spojnych>1) return 0;
    for (int i=1;i<=n;i++){
        if (ile[i]%2==1) return 0;
    }
    return 1;
}
void znajdz_cykl_eulera(int v){
    for (pair<int,int> u:graf[v]){
        if (odw[u.second]==0){
            odw[u.second]=1;
            ile[v]-=1;ile[u.first]-=1;
            znajdz_cykl_eulera(u.first);
        }
    }
    if (ile[v]==0) wynik.push_back(v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    wczytanie();
    if (czy()){
        cout<<"TAK"<<'\n';
        if (ile_spojnych!=0){
            for (int i=1;i<=n;i++){
                if (rozmiar_spojnej[spojna[i]]>1){
                    znajdz_cykl_eulera(i);
                    break;
                }
            }
            for (int i=0;i<wynik.size();i++){
                if (i<wynik.size()-1) cout<<wynik[i]<<' ';
            }
        }
    }
    else cout<<"NIE";
}
