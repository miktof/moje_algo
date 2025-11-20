//Mosty - ³¹cz¹ dwuspójne krawêdziowe
//Punkty artykulacji - ³¹cz¹ dwuspójne wierzcho³kowe
void licze_low(int v,int p){
    odw[v]=1;
    nr_pre++;
    pre[v]=nr_pre;
    low[v]=pre[v];
    int ile_drzewowych=0;
    for (int u:graf[v]){
        if (u==p) continue;
        //drzewowa
        if (odw[u]==0){
            licze_low(u,v);
            ile_drzewowych++;
            low[v]=min(low[v],low[u]);
            if (v!=korzen && low[u]>=pre[v]){
                punkt[v]=1;
            }
            if (low[u] > pre[v]){
                most[{v,u}]=1;
                most[{u,v}]=1;
            }
        }
        //niedrzewowa
        else{
            low[v]=min(low[v],pre[u]);
        }
    }
    if (v==korzen){
        if (ile_drzewowych>1){
            punkt[v]=1;
        }
    }
}
