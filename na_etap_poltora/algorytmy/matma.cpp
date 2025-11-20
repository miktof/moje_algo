//nwd
int nwd(int a,int b){
    if (b==0) return a;
    return nwd(b,a%b);
}
//nww
int nww(int a,int b){
    return (a*b)/(nwd(a,b));
}
// szybkie potegowanie
long long pot(long long a,long long p){
    if (p==0) return 1;
    if (p%2==1){
        return (a*pot(a,p-1))%mod;
    }
    long long pom=pot(a,p/2);
    return (pom*pom)%mod;
}
//symbol newtona
ll symbol_newtona(ll x, ll y){
    ll dol = (silnia[y] * silnia[x-y])%MOD;
    return (silnia[x]*pot(dol,MOD-2))%MOD;
}
//podnoszenie a do potegi b^c
int main(){
    cin>>a>>b>>c;
    potega=pot(b,c,M-1);
    wynik=pot(a,potega,M);
}
