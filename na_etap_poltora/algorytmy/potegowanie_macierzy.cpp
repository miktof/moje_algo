struct macierz{
    ll gl,gp,dl,dp;
};
macierz m1,m;
macierz rek(ll i){
    if (i==1) return {1,1,1,0};
    m=rek(i/2);
    m1={m.gl*m.gl+m.gp*m.dl,m.gl*m.gp+m.gp*m.dp,m.dl*m.gl+m.dp*m.dl,m.dl*m.gp+m.dp*m.dp};
    m1.gl%=MOD;m1.gp%=MOD;m1.dl%=MOD;m1.dp%=MOD;
    if (i%2==0) return m1;
    else{
        m1={m1.gl*1+m1.gp*1,m1.gl*1+m1.gp*0,m1.dl*1+m1.dp*1,m1.dl*1+m1.dp*0};
        m1.gl%=MOD;m1.gp%=MOD;m1.dl%=MOD;m1.dp%=MOD;
        return m1;
    }
}
