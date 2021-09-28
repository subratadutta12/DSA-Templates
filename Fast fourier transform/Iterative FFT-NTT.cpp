#define mod 998244353
#define rt 3
#define irt 332748118

ll bitReverse(ll x, ll log2n)
{
    ll n = 0;
    fr(i, 0, log2n)
    {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}

void ntt(ll a[], ll n, ll invert)
{
    // ns must be a power of 2
    ll b[n + 1];
    fr(i, 0, n)
        b[i] = a[i];
    ll lg = log2(n);
    fr(i, 0, n)
    {
        ll rev = bitReverse(i, lg);
        a[i] = b[rev];
    }

    fr(len, 1, lg + 1)
    {
        ll m = 1 << len;
        ll m2 = m >> 1;
        ll w = 1, wp;
        if (invert)
        {
            ll ns = m2 * 2;
            wp = power(irt, ((mod - 1) / ns));      //For FFT we will just use nth complex root of unity
        }
        else
        {
            ll ns = m2 * 2;
            wp = power(rt, ((mod - 1) / ns));       //For FFT we will just use nth complex root of unity
        }
        fr(i, 0, m2)
        {
            for (ll j = i; j < n; j += m)
            {
                ll u = a[j];
                ll v = mul(a[j + m2], w);
                a[j] = add(u, v);
                a[j + m2] = (u - v + mod) % mod;
            }
            w = mul(w, wp);
        }
    }
    if (invert)
    {
        ll inv_n = modInverse(n);
        fr(i, 0, n)
            a[i] = mul(a[i], inv_n);
    }
    // return a;
}