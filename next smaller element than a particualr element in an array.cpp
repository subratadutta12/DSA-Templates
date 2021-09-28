
/*To find the next small element from an element at
an index in an array*/

stack<pair<ll, ll>>s;
ll ls[n + 5];
fr(i, 0, n)
{
    while (!s.empty() && s.top().fi > h[i])
        s.pop();
    if (s.empty())
        ls[i] = -1;
    else
        ls[i] = s.top().se;
    s.push(mkp(h[i], i));
}