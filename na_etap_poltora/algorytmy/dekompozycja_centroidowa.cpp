void DFS_rozmiar(int v,int oj){
    rozmiar[v]=1;
    for (int u:graf[v]){
        if (u!=oj && byl_centroidem[u]==0){
            DFS_rozmiar(u,v);
            rozmiar[v]+=rozmiar[u];
        }
    }
}
int znajdz_centroid(int v,int oj,int wielkosc){
    for (int u:graf[v]){
        if (u!=oj && byl_centroidem[u]==0 && rozmiar[u]>(wielkosc/2)){
            return znajdz_centroid(u,v,wielkosc);
        }
    }
    return v;
}

void dekcen(int v){
    //obliczanie rozmiarów
    DFS_rozmiar(v,0);
    // szukanie centroida
    int c=znajdz_centroid(v,0,rozmiar[v]);
    byl_centroidem[c]=1;
    centroidy.push_back(c);
    // wywolanie sie dla synów
    for (int u:graf[c]){
        if (byl_centroidem[u]==0) dekcen(u);
    }
}
