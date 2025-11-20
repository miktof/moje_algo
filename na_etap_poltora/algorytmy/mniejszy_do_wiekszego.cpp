if (secik[v].size()<secik[u].size()) swap(secik[v],secik[u]);
for (int x:secik[u]){
    if (secik[v].find(x)==secik[v].end()) secik[v].insert(x);
    else secik[v].erase(x);
}
