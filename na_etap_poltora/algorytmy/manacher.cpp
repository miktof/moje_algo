//Znajdujesz jaki jest promieñ najd³u¿szego palindromu o œrodku w tej literce.
void manacher(string s) {
    s= "$"+s+"%";
    int l=0,r=1;
    for(int i=1;i<s.size();i++){
        promien[i]=max(0,min(r-i,promien[l+r-i]));
        while(s[i-promien[i]]==s[i+promien[i]]){
            promien[i]++;
        }
        if(i+promien[i]>r){
            l=i-promien[i];
            r=i+promien[i];
        }
    }
}
