ld ternary_search(){
    ld p=0;
    ld k=1e9;
    ld ost_p=-1;
    ld ost_k=-1;
    ld mid1,mid2;
    ld bok1,bok2;
    ld roznica=0.0000000001;
    while (k-p>roznica){
        mid1=p+(k-p)/3;
        mid2=k-(k-p)/3;
        bok1=funkcja(mid1);
        bok2=funkcja(mid2);
        if (bok1==bok2){
            p=mid1;
            k=mid2;
        }
        else if (bok1>bok2) p=mid1;
        else k=mid2;
        if (ost_p==p && ost_k==k) break;
        ost_p=p;
        ost_k=k;
    }
    ld wynik=INF;
    for (ld i=p;i<=k;i+=roznica){
        wynik=min(wynik,funkcja(i));
    }
    return wynik;
}
