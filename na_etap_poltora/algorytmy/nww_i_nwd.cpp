//Algorytm euklidesa służy do znajdowania NWD
int nwd(int a,int b){
	if (b==0) return a;
	return nwd(b,a%b);
}
int nww(int a,int b){
	return (a*b)/(nwd(a,b));
}
