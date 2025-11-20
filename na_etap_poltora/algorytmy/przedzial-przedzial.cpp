//Mikolaj Tofiluk
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=8;
int Tree[MAXN*2+5];
int Lazy[MAXN*2+5]; //to co mam przekazac poddrzewu

void push(int v,int u1,int u2,int ml,int mr,int l,int r){
    Lazy[u1]+=Lazy[v];
	Lazy[u2]+=Lazy[v];
	int odl_lewa=min(r,(ml+mr)/2)-max(l,ml)+1;
	int odl_prawa=min(r,mr)-max(l,(ml+mr)/2)+1;
	Tree[u1]+=max(0,Lazy[v]*odl_lewa);
	Tree[u2]+=max(0,Lazy[v]*odl_prawa);
	Lazy[v]=0;

}
void akt(int v,int ml,int mr,int l,int r,int val){
	if (r<ml || l>mr){
		return;
	}
	if (ml>=l && mr<=r){
        Tree[v]+=val*(mr-ml+1);
        Lazy[v]+=val;
	}
	else{
		push(v,v*2,v*2+1,ml,mr,l,r);
		akt(v*2,ml,(ml+mr)/2,l,r,val);
		akt(v*2+1,(ml+mr)/2+1,mr,l,r,val);
		Tree[v]=Tree[v*2]+Tree[v*2+1];
	}
}
int wynik(int v,int ml,int mr,int l,int r){
    if (r<ml || l>mr) return 0;
    if (ml>=l && mr<=r) return Tree[v];
	push(v,v*2,v*2+1,ml,mr,l,r);
	return wynik(v*2,ml,(ml+mr)/2,l,r)+wynik(v*2+1,(ml+mr)/2+1,mr,l,r);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    int t,a,b,wart;
    for (int i=0;i<q;i++){
        cin>>t;
        if (t==0){
            cin>>a>>b>>wart;
            akt(1,MAXN,MAXN*2-1,a+MAXN,b+MAXN,wart);
        }
        if (t==1){
            cin>>a>>b;
            cout<<wynik(1,MAXN,MAXN*2-1,MAXN+a,MAXN+b)<<'\n';
        }
    }
}
