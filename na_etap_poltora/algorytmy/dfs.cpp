// DFS - odwiedza wszystkie wierzcholki
void DFS (int v){
	odw[v]=1;
	for (int u:graf[v]){
		if (odw[u]==0) DFS(u);
	}
}
