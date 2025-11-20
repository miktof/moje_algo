//tu liczymy ile roznych liczb wystepuje na przedzialach
bool porownanie(pair<pair<int, int>, int> niby_a, pair<pair<int, int>, int> niby_b) {
    pair<int, int> ap = niby_a.first;
    pair<int, int> bp = niby_b.first;
    if (ap.first/pierw<bp.first/pierw) return 1;
    if (ap.first/pierw>bp.first/pierw) return 0;
    return ap.second<bp.second;
}
void mo(){
    int l=zap[0].first.first;int r=zap[0].first.second;int indeks=zap[0].second;int wynik=0;
    for (int i=l;i<=r;i++){
        ile[tab[i]]++;
        if (ile[tab[i]]==1) wynik++;
    }
    odp[indeks]=wynik;
    int sl=l;int sr=r;
    for (int j=1;j<q;j++){
        l=zap[j].first.first;r=zap[j].first.second;indeks=zap[j].second;
        for (int i=sl;i<l;i++){
            ile[tab[i]]--;
            if (ile[tab[i]]==0) wynik--;
        }
        for (int i=sl-1;i>=l;i--){
            ile[tab[i]]++;
            if (ile[tab[i]]==1) wynik++;
        }
        for (int i=sr+1;i<=r;i++){
            ile[tab[i]]++;
            if (ile[tab[i]]==1) wynik++;
        }
        for (int i=sr;i>r;i--){
            ile[tab[i]]--;
            if (ile[tab[i]]==0) wynik--;
        }
        sl=l;sr=r;
        odp[indeks]=wynik;
    }
}
