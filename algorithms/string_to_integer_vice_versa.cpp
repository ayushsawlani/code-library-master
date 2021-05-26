ll strtoi(string s)
{
    ll len_s=s.size();
    ll ans=0;
    for(ll i=len_s-1,x=1;i>=0;i--,x=x*10)
    {
        ans+=(((ll)(s[i])-48)*x);
    }
    return ans;
}
string itos(ll i)
{
    string s="";
    if(i==0)
        s.push_back('0');
    while(i>0)
    {
        s.push_back((char)((i%10)+48));
        i=i/10;
    }
    ll len_s=s.size();
    for(ll i=0;i<(len_s+1)/2;i++)
    {
        ll temp=s[i];
        s[i]=s[len_s-i-1];
        s[len_s-i-1]=temp;
    }
    return s;
}