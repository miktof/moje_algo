void akt(int a, int b, int wartosc){
    int l = a + M, r = b + M;
    int dlugosc = 1;
    obciazenie[l] += wartosc;
    suma[l] += wartosc;
    if(l!=r){
        obciazenie[r] += wartosc;
        suma[r] += wartosc;
    }
    while(l > 0){
        if(l < r -  1){
            if(l%2 == 0){
                suma[l+1] += wartosc*dlugosc;
                obciazenie[l+1] += wartosc;
            }
            if(r%2 == 1){
                suma[r - 1] += wartosc*dlugosc;
                obciazenie[r - 1] += wartosc;
            }
        }

        if(r < M){
        	suma[l] = suma[l*2] + suma[l*2 + 1] + obciazenie[l]*dlugosc;
            suma[r] = suma[r*2] + suma[r*2 + 1] + obciazenie[r]*dlugosc;o
		}

        r>>=1;
        l>>=1;
        dlugosc<<=1;
    }
}

int query(int a, int b,int zet){
    int l = a + M, r = b + M,dl_r,dl_l;
    int dlugosc = 1;dl_l = 1;
    if(l!=r)
        dl_r = 1;
    else
        dl_r = 0;

    long long wynik = 0;
    while(l > 0){
		wynik += obciazenie[l]*dl_l + obciazenie[r]*dl_r;
        if(l < r -  1){
            if(l%2 == 0){
                wynik+= suma[l+1];
                dl_l+= dlugosc;
            }
            if(r%2 == 1){
                wynik+= suma[r-1];
                dl_r+= dlugosc;
            }
        }
        r>>=1;
        l>>=1;
        dlugosc<<=1;
    }
    return wynik;
}
