//W tym przypadku chcieliœmy obliczyæ najkrótsz¹ mo¿liw¹ drogê o parzystej wadze i o nie parzystej wadze z 1 dla ka¿dego wierzcho³ka.
void wczytanie(){
    cin>>n>>m;
    int a,b;
    ll c;
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        if (c%2==0){
            graf[a].push_back({b,c});
            graf[b].push_back({a,c});
            graf[a+n].push_back({b+n,c});
            graf[b+n].push_back({a+n,c});
        }
        else{
            graf[a].push_back({b+n,c});
            graf[b].push_back({a+n,c});
            graf[a+n].push_back({b,c});
            graf[b+n].push_back({a,c});
        }
    }
}
void dijkstra(int start){
    for (int i=0;i<=2*n;i++) odl[i]=INF;
    odl[start] = 0;
    priority_queue <pair <long long, int> > q;
    q.push({0,1});
    int v,u;
    ll c;
    while(q.size()){
        v = q.top().second;
        q.pop();
        if(odw[v]) continue;
        odw[v] = true;
        for(pair<int,long long> u_c : graf[v]){
            u=u_c.first;
            c=u_c.second;
            if (odl[u]>odl[v]+c){
                odl[u] = odl[v] + c;
                q.push({-odl[u], u});
            }
        }
    }
}
