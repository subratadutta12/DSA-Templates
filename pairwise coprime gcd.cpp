#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1e18+5
#define mod 1000000007
#define MAXN 1000005
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
#define nob __builtin_popcount
#define des greater<ll>()
#define fi first
#define se second
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
ll spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        spf[i] = i;
    for (ll i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (ll i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
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

//To find if each pair of element in an array is coprime


int main()
{
    fio;
    ll n;
    cin >> n;
    ll a[n + 5];
    input(a, n);
    sieve();
    map<ll, vector<ll>>mp;
    fr(i, 0, n)
    {
        ll k = a[i];
        set<ll>s;
        s.clear();
        while (k != 1)
        {
            s.insert(spf[k]);
            k /= spf[k];
        }
        for (auto j : s)
            mp[j].pb(i);
    }
    ll g = 0;
    fr(i, 0, n - 1)
    {
        ll k = a[i];
        set<ll>s;
        s.clear();
        while (k != 1)
        {
            s.insert(spf[k]);
            k /= spf[k];
        }
        ll f = 0;
        //cout<<a[i]<<" a[i]====\n";
        for (auto j : s)
        {
            //cout<<j<<"===\n";
            /*for(auto l:mp[j])
            {
                //cout<<l<<" ";
            }*/
            //cout<<"\n";
            ll d = mp[j].end() - upper_bound(mp[j].begin(), mp[j].end(), i);
            if (d > 0)
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            //cout<<"heref ids 0\n";
            g++;
        }
    }
    if (g == (n - 1))
        cout << "pairwise coprime\n";
    else
    {
        ll h = a[0];
        fr(i, 1, n)
        {
            h = gcd(h, a[i]);
        }
        //cout<<h<<"\n";
        if (h == 1)
            cout << "setwise coprime\n";
        else
            cout << "not coprime\n";
    }
    return 0;
}
