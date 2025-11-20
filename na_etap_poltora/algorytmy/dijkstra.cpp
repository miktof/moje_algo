void dijkstra(int start){
    for (int i=0;i<=n;i++) odl[i]=INF;
    odl[start] = 0;
    priority_queue <pair <long long, int> > q;
    q.push(make_pair(0, start));
    int v;
    while(q.size()){
        v = q.top().second;
        q.pop();
        if(odw[v]) continue;
        odw[v] = true;
        for(pair<int,long long> u : graf[v]){
            if(odl[u.first] > odl[v] + u.second){
                odl[u.first] = odl[v] + u.second;
                q.push({-odl[u.first], u.first});
            }
        }
    }
}
