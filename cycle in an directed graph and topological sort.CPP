
//Finding cycle in a directed graph
ll dfs(ll u, vector<ll>a[])
{
    vis[u] = 1;
    rec[u] = 1;
    //cout<<"u== "<<u<<"\n";
    for (ll i = 0; i < a[u].size(); i++)
    {
        if (vis[a[u][i]] == 0)
        {
            ll h = dfs(a[u][i], a);
            if (h == 1)
                return h;
        }
        else if (rec[a[u][i]] == 1)
        {   //cout<<"cycle==="<<u<<"\n";
            return 1;
        }
    }
    rec[u] = 0;
    return 0;
}


//Topological Sorting
stack<ll>s;
void tps(ll u, vector<ll>a[])
{
    vis[u] = 1;
    //cout<<"u== "<<u<<"\n";
    for (ll i = 0; i < a[u].size(); i++)
    {
        if (vis[a[u][i]] == 0)
        {
            tps(a[u][i], a);
        }
    }
    s.push(u);
}

