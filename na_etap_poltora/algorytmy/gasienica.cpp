//Algorytm gąsianicy służy do znalezienia w ciągu spójnego podciągu o danej sumie

int gasienica(int n,int szuk){
	int wyn=1e9;
	int suma=tab[0];
	int glowa=1;
	int ogon=0;
	while (glowa<n){
		suma+=tab[glowa];
		if (suma==szuk) wyn=min(wyn,glowa-ogon+1);
		while (ogon<glowa && suma>=szuk){
			suma-=tab[ogon];
			ogon++;
			if (suma==szuk) wyn=min(wyn,glowa-ogon+1);
		}
		glowa++;
	}
	return wyn;
}
