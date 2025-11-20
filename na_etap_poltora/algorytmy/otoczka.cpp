bool porownanie(pair<long long,long long> B,pair<long long,long long> C){
    if (B==A) return 1;
    if (C==A) return 0;
    if((B.second-A.second)*(C.first-A.first)==(B.first-A.first)*(C.second-A.second)){
        if (B.first==C.first) return B.second<C.second;
        return B.first<C.first;
	}
	return (B.second-A.second)*(C.first-A.first)<(B.first-A.first)*(C.second-A.second);
}
void sortowanie_katowe(){
    sort(punkty,punkty+n,porownanie);
}
long long iloczyn_wektorowy(pair<long long,long long> X,pair<long long,long long> Y,pair<long long,long long> Z){
    long long x1=Z.first-X.first, y1=Z.second-X.second;
    long long x2=Y.first-X.first, y2=Y.second-X.second;
    return x1*y2 - x2*y1;
}
stack<pair<long long,long long>> otoczka_wypukla(){
    stack<pair<long long,long long>> stos;
    stos.push(punkty[0]);
    pair<long long,long long> X=punkty[0], Y=punkty[1];
    for (int i=2;i<=n;i++){
        while (iloczyn_wektorowy(X,Y,punkty[i])>=0){
            Y=X;
            stos.pop();
            if (stos.empty()) break;
            X=stos.top();
        }
        stos.push(Y);
        X=Y;
        Y=punkty[i];
    }
    return stos;
}
