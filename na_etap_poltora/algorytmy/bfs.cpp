//BFS służy do znajdowania najkrótszej ścieżki z jednego wierzchołka do wszystkich w grafie nieważonym lub o jednakowych wagach.
void BFS(int start){
	queue <int> q;
	q.push(start);
	odw[start]=1;
	while (q.size()){
		int v=q.front();
		q.pop();
		odw[v]=1;
		for (int u:graf[v]){
			if (odw[u]==0){
				odw[u]=1;
				odl[u]=odl[v]+1;
				q.push(u);
			}
		}
	}
}
