for (int i=1;i<=s.size();i++){
    H1[i]=((H1[i-1]*P)%M1 + int(s[i-1])-96);
    H1[i]%=M1;
}
