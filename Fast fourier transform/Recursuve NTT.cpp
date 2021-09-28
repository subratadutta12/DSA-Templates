/*The difference from fft is only the nth root of unity. In FFT we have used complex number e^((i*2*PI)/n) as nth root, but in NTT we will use nth primitive root of mod ,i.e. nth-root(say w)= rt^((mod-1)/n). So first root is r1 = w^0 ; r2 = w^1 ; r3 = w^3......rk = w^k*/

// For mod = 998244353 = 7*17*(2^23)+1 , so for this we can get upto 23rd root of unity and primitive root will be 3 , nth-root(say w)= 3^((mod-1)/n)

#define mod 998244353
#define rt 3
#define irt 332748118

void ntt(ll a[], ll ns, ll invert)
{
    // ns must be a power of 2
    if (ns == 1)
        return;

    ll a0[ns / 2], a1[ns / 2];
    for (ll i = 0; 2 * i < ns; i++)
    {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    ntt(a0, ns / 2, invert);
    ntt(a1, ns / 2, invert);

    ll w = 1;
    ll wp;
    if (invert)
    {
        wp = power(irt, ((mod - 1) / ns));
    }
    else
        wp = power(rt, ((mod - 1) / ns));

    for (ll i = 0; 2 * i < ns; i++)
    {
        a[i] = add(a0[i], mul(w, a1[i]));
        a[i + (ns / 2)] = (a0[i] % mod) - mul(w, a1[i]);
        a[i + (ns / 2)] += mod;
        a[i + (ns / 2)] %= mod;
        if (invert)
        {
            a[i] = mul(a[i], modInverse(2));
            a[i + (ns / 2)] = mul(a[i + (ns / 2)], modInverse(2));
        }
        w = mul(w, wp);
    }
}