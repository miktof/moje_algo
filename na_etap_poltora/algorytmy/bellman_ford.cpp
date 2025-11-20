bool czy_ujemny_cykl(){
    for (int i=1;i<=n;i++) odl[i]=INF;
    odl[1]=0;
    for (int k=0;k<n-1;k++){
        for (int i=0;i<m;i++){
            if (odl[krawedzie[i].a]+krawedzie[i].c < odl[krawedzie[i].b]){
                odl[krawedzie[i].b]=odl[krawedzie[i].a]+krawedzie[i].c;
            }
        }
    }
    for (int i=0;i<m;i++){
        if (odl[krawedzie[i].a]+krawedzie[i].c < odl[krawedzie[i].b]){
            return 1;
        }
    }
    return 0;

}
