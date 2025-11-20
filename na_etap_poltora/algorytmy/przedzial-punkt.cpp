//Drzewo przedział-punkt pozwala nam aktualizować wynik na przedziale i odczytać wynik dla 1 punktu
int wynik(int ind){
	int w=1;
	while (ind>0){
		w*=D[ind];
		ind/=2;
	}
	return w;
}
void akt(int l,int r,int wart){
	while (r>=l){
		if (l%2==1){
			D[l]*=wart;
			l++;
		}
		if (r%2==0){
			D[r]*=wart;
			r--;
		}	
		l/=2;
		r/=2;
	}
}