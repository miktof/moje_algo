// ALOGRYTM KRUSKALA
//Funkcja Find
int Znajdz(int w){
    if (t[w]==w){
        return w;
    }
    else{
        t[w]=Znajdz(t[w]);
        return t[w];
    }
}
// Funkcja Union
void Polacz(int a,int b){
    a=Znajdz(a);
    b=Znajdz(b);
    if (gl[a]<=gl[b]){
        t[a]=b;
        if (gl[a]==gl[b]) gl[b]++;
    }
    else t[b]=a;
}

//funkcja do sortowania krawêdzi
 bool porownanie(pair<int,krawedz> p1,pair<int,krawedz> p2){
    return p1.first<p2.first;
 }

 //Jeœli s¹ w innych spojnych to je ³¹czymy, jeœli s¹ w tych samych nie robimy nic
void czy_w_mst(int cena, int p, int k, int indeks){
    if (Znajdz(p)==Znajdz(k)) wyniki[indeks]=false;
    else{
        Polacz(p,k);
        wyniki[indeks]=true;
    }
 }
 //MST -funkcja znajdujace najmniejsze drzewo rozpinajace,  idziemy po najtañszych krawêdziach
void mst(){
    for (int x=1;x<=n;x++){
        t[x]=x;
    }
    sort(krawedzie,krawedzie+m,porownanie);
    for (int i=0;i<m;i++){
        czy_w_mst(krawedzie[i].first, krawedzie[i].second.w1, krawedzie[i].second.w2, krawedzie[i].second.ind);
    }
}


//ALGORYTM PRIMA:
//Wybieramy w grafie dowolny wierzcho³ek startowy.
//Dopóki drzewo nie pokrywa ca³ego grafu, znajdujemy krawêdŸ o najni¿szym koszcie spoœród wszystkich krawêdzi prowadz¹cych od wybranych ju¿ wierzcho³ków do wierzcho³ków jeszcze niewybranych.
//Znalezion¹ krawêdŸ dodajemy do drzewa rozpinaj¹cego.
