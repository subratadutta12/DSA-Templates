#define ll long long
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define inf INT_MAX
#define fi first
#define se second
#define pb push_back

ll n, vector<vector<ll>> a[100005];
vector<pair<ll, pair<ll, ll>>>v;
ll rank[100005], par[100005];

void makeset()
{
    fr(i, 0, n + 1)
    {
        par[i] = i;
        rank[i] = 0;
    }
}

int findpar(int node)
{
    if (node == par[node])
        return node;

    return par[node] = findpar(par[node]);
}

void union(int u, int v)
{
    u = findpar(u);
    v = findpar(v);

    if (rank[u] < rank[v])
    {
        par[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        par[v] = u;
    }
    else
    {
        par[v] = u;
        rank[u]++;
    }
}

vector<pair<ll, ll>>mst[100005];

void kruskal()
{
    fr(i, 1, n + 1)
    {
        for (auto j : a[i])
        {
            v.pb({j[1], {i, j[0]}});
        }
    }
    sort(v.begin(), v.end());
    ll ln = v.size();
    ll min_wt = 0;
    makeset();
    fr(i, 0, ln)
    {
        if (findpar(v[i].se.fi) != findpar(v[i].se.se))
        {
            min_wt += v[i].fi;
            mst[v[i].se.fi].pb({v[i].se.se, v[i].fi});
            union(v[i].se.fi, v[i].se.se);
        }
    }
}