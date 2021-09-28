/*A bus stops at n bus stops, each bus stop having a[i] people. The bus needs to take in all the people on the bus. People from 1 bus stop get down before the next bus stop arrives. They use a resizing tech which allows the bus to be resized to whatever capacity they want. This action can be done only b times at max. The uselessness of the bus is the summation of a total number of unoccupied seats across n stops. Find the minimum uselessness the bus can achieve if the resizing tech is used optimally. 1<=a[i]<=10^6, 1<=b<=n<=400
Ex 1:
a = [10 20] b = 0
Ans:10
Explanation – the resizing tech cannot be applied. hence the capacity of the bus is 20 initially. in the first stop, 20-10 seats were unused. in the second stop 20 – 20 seats are unused. Total unused seats = 10

Ex 2:
a = [10 20 30] b = 1
Ans: 10
Explanation – the resizing tech can be applied only once. The capacity of the bus is 10 initially. in the first stop 10-10 seats unused = 0. in the second stop, the tech is used to resize to 30. 30 – 20 seats unused.

In the third stop,  30-30 seats unused

Total unused seats = 10.*/



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

    for(ll i=3;i*i<MAXN;i+=2)
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
/*ll fac[MAXN];
ll inv[MAXN];
void fact(ll p=mod)
{
    fac[0] = 1;
    for (ll i = 1 ; i < MAXN; i++)
        fac[i] = fac[i - 1] * i % p;
    for(ll i=0;i<MAXN;i++)
    inv[i]=modInverse(fac[i]);
}
ll ncrMod(ll n, ll r, ll p = mod)
{
    if (r == 0)
        return 1;
    return (fac[n] * inv[r] % p *
            inv[n-r] % p) % p;
}*/
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

ll n, k, a[405];

class seg_tree
{

public:
    ll tree[1000];

    // function to build the tree
    void build( vector<ll>&a, int n)
    {
        // insert leaf nodes in tree, array a has 0-based indexing
        for (int i = 0; i < n; i++)
            tree[n + i] = a[i];

        // build the tree by calculating parents, tree will have 1 based indexing
        for (int i = n - 1; i > 0; --i)
            tree[i] = min(tree[i << 1] , tree[i << 1 | 1]);
    }

    // function to update a tree node
    void update(ll p, ll value, int n)
    {
        // set value at position p 0-based indexing
        tree[p + n] = value;
        p = p + n;

        // move upward and update parents
        for (int i = p; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    // function to get sum on interval [l, r), 0-based indexing
    ll query(int l, int r, int n)
    {
        ll res = inf;

        // loop to find the sum in the range
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = min(res, tree[l++]);

            if (r & 1)
                res = min(res, tree[--r]);
        }

        return res;
    }

};


int main()
{
    fio;
    cin >> n >> k;
    fr(i, 0, n)
    {
        cin >> a[i];
    }
    ll dp[n + 5][k + 5], dp2[n + 5][k + 5];
    memset(dp, 0, sizeof(dp));
    fr(i, 0, n + 1)
    {
        fr(j, 0, k + 1)
        dp2[i][j] = inf;
    }
    for (ll l = n - 1; l >= 0; l--)
    {
        // cout<<"l===== "<<l<<"\n";
        fr(i, 0, k + 1)
        {
            vector<ll>v;
            v.clear();
            if (i > 0)
            {
                fr(j, 0, n)
                v.pb(dp[j][i - 1]);
            }
            else
            {
                fr(j, 0, n)
                v.pb(inf);
            }
            seg_tree t;
            t.build(v, n);
            fr(j, 0, n)
            {
                if (a[j] >= a[l])
                {
                    ll h = min(t.query(0, j, n), dp[j][i]);
                    h = min(h, t.query(j + 1, n, n));
                    // cout<<"j-i-h== "<<j<<" "<<i<<" "<<h<<"\n";
                    if (h != inf)
                        dp2[j][i] = (a[j] - a[l]) + h;
                    else
                        dp2[j][i] = inf;
                    // cout<<dp2[j][i]<<"\n";
                }
                else
                    dp2[j][i] = inf;
            }
        }
        fr(i, 0, k + 1)
        {
            fr(j, 0, n)
            {
                dp[j][i] = dp2[j][i];
                dp2[j][i] = inf;
            }
        }
    }
    ll ans = inf;
    fr(i, 0, n)
    ans = min(ans, dp[i][k]);
    cout << ans << "\n";
    return 0;
}
