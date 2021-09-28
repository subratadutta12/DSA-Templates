#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,a,b) for(long long i=a;i<b;i++)

ll n, rank[100005], par[100005];

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


