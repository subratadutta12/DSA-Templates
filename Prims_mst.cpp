#define ll long long
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define inf INT_MAX
#define fi first
#define se second

ll n, vector<vector<ll>> a[100005];
ll key[100005], mst[100005], par[100005];

// par array contains all edges and key array contains all weight of our mst

void prims()
{
    fr(i, 0, n + 1)
    {
        key[i] = inf;
        par[i] = -1;
        mst[i] = 0;
    }
    key[0] = 0;
    set<pair<ll, ll>>s;
    s.insert({0, 1});
    fr(i, 0, n - 1)
    {
        ll u = (*s.begin()).se;
        s.erase(s.begin());
        mst[u] = 1;
        for (auto j : a[u])
        {
            if (mst[j[0]] == 0 && j[1] < key[j[0]])
            {
                if (key[j[0]] != inf)
                {
                    s.erase({key[j[0]], j[0]});
                }
                key[j[0]] = j[1];
                par[j[0]] = u;
                s.insert({j[1], j[0]});
            }
        }
    }
}
