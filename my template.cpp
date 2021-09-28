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
#define frn(i,a,b,n) for(long long i=a;i<=b;i=i+n)
#define gcd(x,y) __gcd(x,y)
#define ld long double
#define um unordered_map
#define mkp make_pair
#define b_s binary_search
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
ll b_srch(ll arr[], ll l, ll r, ll x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (arr[m] == x)
			return m;
		if (arr[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
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
/* Iterative Function to calculate (x^y)%p
  in O(log y) */
ll power(ll x, ll y, ll p)
{
	ll res = 1;      // Initialize result

	x = x % p;  // Update x if it is more than or
	// equal to p

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}
// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
	return power(n, p - 2, p);
}
// Returns nCr % p using Fermat's little
// theorem.
ll nCrModPFermat(ll n, ll r, ll p)
{
	// Base case
	if (r == 0)
		return 1;

	// Fill factorial array so that we
	// can find all factorial of r, n
	// and n-r
	ll fac[n + 1];
	fac[0] = 1;
	for (ll i = 1 ; i <= n; i++)
		fac[i] = fac[i - 1] * i % p;

	return (fac[n] * modInverse(fac[r], p) % p *
	        modInverse(fac[n - r], p) % p) % p;
}

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





int main() {
	fio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	return 0;
}
