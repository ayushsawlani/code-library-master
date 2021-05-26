vector <vector <ll>> generatemst(vector <vector <ll>> &G, ll *c,ll *pi,ll *priority,map <pair <ll,ll>,ll> &wt)
{
    vector <vector <ll>> mst;
    ll len_g=G.size();
    for(ll i=0;i<len_g;i++)
    {
        vector <ll> temp;
        mst.push_back(temp);
    }
    set <pair <ll,ll>> pq;
    pair <ll,ll> temp;
    temp.first=0;
    temp.second=0;
    c[0]=1;
    pi[0]=-1;
    pq.insert(temp);
    while(!(pq.empty()))
    {
        pair <ll,ll>visited=(*(pq.begin()));
        pq.erase(pq.begin());
        c[visited.second]=2;
        ll parent=pi[visited.second];
        if(parent!=-1)
        {
            mst[parent].push_back(visited.second);
            mst[visited.second].push_back(parent);
        }   
        for(auto i=G[visited.second].begin();i!=G[visited.second].end();i++)
        {
            pair <ll,ll> current;
            current.first=visited.second;
            current.second=(*i);
            if(c[(*i)]==1)
            {
                if(wt[current]<priority[*i])
                {
                    pair <ll,ll> tobeerased;
                    tobeerased.first=priority[*i];
                    tobeerased.second=(*i);
                    auto er=pq.find(tobeerased);
                    pq.erase(er);
                    c[*i]=0;
                }
            }
            if(c[(*i)]==0)
            {
                priority[(*i)]=wt[current];
                pair <ll,ll> tobepushed;
                tobepushed.first=priority[*i];
                tobepushed.second=(*i);
                pq.insert(tobepushed);
                pi[*i]=visited.second;
                c[*i]=1;
            }
        }
    }
    return mst;
}