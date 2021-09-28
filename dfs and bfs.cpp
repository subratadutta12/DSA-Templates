ll vis[200005] = {0}, bn[200005] = {0}, un[200005] = {0}, ps = -1;
vector<ll>v;
vector<ll>a[200005];
void bfs(ll i)
{
	queue<ll> q;
	q.push(i);
	vis[i] = 1;
	while (!q.empty())
	{
		ll z = q.front();
		q.pop();
		if (vis[z] == 0 && a[z].size() == 1)
			v.pb(dis[z]);
		for (auto j : a[z])
		{
			if (vis[j] == 0)
			{
				dis[j] = dis[z] + 1;
				if (a[j].size() == 1)
					v.pb(dis[j]);
				vis[j] = 1;
				q.push(j);
			}
		}
	}
}



//general bfs
void bfs(ll i)
{
	queue<ll> q;
	q.push(i);
	vis[i] = 1;
	while (!q.empty())
	{
		ll z = q.front();
		q.pop();
		for (auto j : a[z])
		{
			if (vis[j] == 0)
			{
				vis[j] = 1;
				q.push(j);
			}
		}
	}
}



//general dfs
ll dfs(int u)
{
	vis[u] = 1;
	//cout << u << " ";
	for (int i = 0; i < a[u].size(); i++)
	{
		if (vis[a[u][i]] == 0)
		{
			dfs(a[u][i]);
		}
	}
}





ll dfs(int u)
{
	ps++;
	vis[u] = 1;
	un[u] += ps;
	//cout << u << " ";
	for (int i = 0; i < a[u].size(); i++)
	{
		if (vis[a[u][i]] == 0)
		{
			bn[u] += dfs(a[u][i]) + 1;
		}
	}
	ps--;
	return bn[u];
}


ll ans = 0;
ll pr = 0;
ll no[200005] = {0};
void dfs2(int u)
{
	vis[u] = 1;
	pr += no[u];
	if (no[u] == 0)
		ans += pr;
	//cout<<"pr== "<<pr<<"\n";
	//cout << u << " ";
	for (int i = 0; i < a[u].size(); i++)
	{
		if (vis[a[u][i]] == 0)
		{
			//ans+=no[a[u][i]];
			dfs2(a[u][i]);
		}
	}
	pr -= no[u];
	//return bn[u];
}
