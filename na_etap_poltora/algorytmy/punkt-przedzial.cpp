//Drzewo przedział-punkt pozwala nam aktualizować wynik poprzez zmianę wartości 1 punktu i odczytać wynik na przedziale
void akt(int wart,int ind){
    D[ind]=max(D[ind],wart);
    while (ind>1){
    	ind/=2;
        D[ind]=max(D[ind*2],D[ind*2+1]);
    }
}
int wynik(int l, int r){
    int w=0;
    while (l<r){
        if (l%2==1){
            w=max(w,D[l]);
            l++;
        }
        if (r%2==0){
            w=max(w,D[r]);
            r--;
        }
        l/=2;
        r/=2;
    }
    if (l==r) w=max(w,D[l]);
    return w;
}
