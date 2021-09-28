#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1e18+5
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
#define lcm(x,y) (x*y)/gcd(x,y)
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




int main()
{
    fio;
    ll n;
    cin >> n;
    ll l[n + 5], r[n + 5];
    fr(i, 0, n)
    {
        cin >> l[i] >> r[i];
    }
    vector<pair<ll, ll>>v;
    fr(i, 0, n)
    {
        //make a vector of all end points
        v.pb(mkp(l[i], i));
        v.pb(mkp(r[i], i));
    }
    //sort the vector
    sortv(v);
    ll ln = v.size();
    set<pair<ll, ll>>s;
    ll f = 0;
    fr(i, 0, ln)
    {
        // cout<<v[i].fi<<" "<<v[i].se<<"\n";
        auto it = s.find(v[i]);
        if (it != s.end())
        {
            s.erase(it);
            continue;
        }
        ll d = r[v[i].se];
        // cout<<"y=== "<<d<<"\n";
        for (auto j : s)
        {
            if (j.fi < d)
            {
                // 2 line segment intersects
                f++;
            }
            else
                break;
            if (f >= n)
                break;
        }
        if (f >= n)
            break;
        s.insert(mkp(d, v[i].se));
    }
    return 0;
}
