// Find and Union służy do tworzenia krawędzi w grafie, aby stworzyc silnie spójne składowe
//Funkcja Find
int Znajdz(int w){
    if (t[w]==w){
        return w;
    }
    else{
        t[w]=Znajdz(t[w]);
        return t[w];
    }
}
//Funkcja Union
void Polacz(int a,int b){
    int a=Znajdz(a);
    int b=Znajdz(b);
    if (gl[a]<gl[b]){
        t[a]=b;
    }
    else if (gl[a]>gl[b]){
        t[b]=a;
    }
    else{
        t[a]=b;
        gl[b]++
    }
}
