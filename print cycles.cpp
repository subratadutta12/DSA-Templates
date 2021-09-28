#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define MAXN 100005
#define ll long long
#define pb push_back
#define sortv(v) sort(v.begin(),v.end())
#define tc(t) int t;cin>>t;while(t--)
#define copy copy_n
#define fr(i,a,b) for(long long i=a;i<b;i++)
#define frr(i,a,b) for(long long i=a;i>=b;i--)
#define frn(i,a,b,n) for(long long i=a;i<=b;i=i+n)
#define gcd(x,y) __gcd(x,y)
#define ld long double
#define um unordered_map
#define mkp make_pair
#define b_s binary_search
#define des greater<ll>()
#define fi first
#define se second
#define PI 3.1415926535
#define FP(n) fixed<<setprecision(n)
ll mul(ll a, ll b, ll p = mod) {return ((a % p) * (b % p)) % p;}
ll add(ll a, ll b, ll p = mod) {return (a % p + b % p) % p;}
void input(ll a[], ll sz) {fr(i, 0, sz) cin >> a[i];}
void print(ll a[], ll sz) {fr(i, 0, sz) {if (i == sz - 1) cout << a[i] << "\n"; else cout << a[i] << " ";}}
ll maxr(ll a[], ll sz) {ll ma; fr(i, 0, sz) {if (i == 0) ma = a[i]; else if (a[i] > ma) ma = a[i];} return ma;}
ll minr(ll a[], ll sz) {ll mi; fr(i, 0, sz) {if (i == 0) mi = a[i]; else if (a[i] < mi) mi = a[i];} return mi;}
ll isprm(ll n) {
    if (n <= 1)  return 0;
    if (n <= 3)  return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
/*ll spf[MAXN];
void sieve()
{
    spf[1]=1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for(ll i=3;i*i<MAXN;i++)
    {
        if (spf[i]==i)
        {
            for (int j=i*i;j<MAXN;j+=i)
                if (spf[j]==j)
                    spf[j]=i;
        }
    }
}*/
ll power(ll x, ll y, ll p = mod)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
ll modInverse(ll n, ll p = mod)
{
    return power(n, p - 2, p);
}
ll ncrMod(ll n, ll r, ll p = mod)
{
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1 ; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;
    return (fac[n] * modInverse(fac[r], p) % p *
            modInverse(fac[n - r], p) % p) % p;
}
//a+b=xor(a,b)+2*(a&b)//
struct comp
{
    bool operator()(const pair<ll, ll> &a,
                    const pair<ll, ll> &b)const
    {
        if (a.fi == b.fi)
        {
            return (a.se > b.se); //second elem in descending
        }
        return (a.first < b.first);//first elem in ascending
    }
};

ll n, m, k, col[MAXN], par[MAXN], f = 0;
vector<ll>a[100005];
map<ll, vector<ll>>cyc;

//dfs to print cycles
void dfs(ll u)
{
    //cout<<"dfs=="<<u<<"\n";
    col[u] = 1;
    for (auto i : a[u])
    {
        //cout<<i<<" "<<col[i]<<"\n";
        if (col[i] == 2 || i == par[u])
            continue;
        else if (col[i] == 1)
        {
            f++;
            ll cur = u;
            while (1)
            {
                cyc[f].pb(cur);
                //cout<<"curr=="<<cur<<"\n";
                if (cur == i)
                    break;
                cur = par[cur];
            }
        }
        else if (col[i] == 0)
        {
            par[i] = u;
            dfs(i);
        }
    }
    col[u] = 2;
}


vector<ll>lv[2];
void dfst(int u, ll f, ll pr)
{
    if (f % 2 == 0)
        lv[0].pb(u);
    else
        lv[1].pb(u);
    for (int i = 0; i < a[u].size(); i++)
    {
        if (a[u][i] != pr)
        {
            dfst(a[u][i], f + 1, u);
        }
    }
}






int main()
{
    fio;
    cin >> n >> m >> k;
    fr(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    fr(i, 0, MAXN)
    col[i] = 0;
    dfs(1);
    if (cyc.size() == 0)
    {
        cout << "1\n";
        dfst(1, 0, 0);
        fr(i, 0, 2)
        {
            ll re = ceil(k / (ld)2);
            if (lv[i].size() >= re)
            {
                fr(j, 0, re)
                cout << lv[i][j] << " ";
                cout << "\n";
                return 0;
            }
        }
    }
    for (auto i : cyc)
    {
        if (i.se.size() <= k)
        {
            cout << "2\n";
            cout << i.se.size() << "\n";
            for (auto j : i.se)
                cout << j << " ";
            cout << "\n";
            return 0;
        }
    }
    ll h = 0;
    cout << "1\n";
    for (auto i : cyc[1])
    {
        if (h == 0)
        {
            cout << i << " ";
            h = 1;
        }
        else if (h == 1)
            h = 0;
    }
    return 0;
}
