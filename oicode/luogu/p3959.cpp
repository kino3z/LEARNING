// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace baozang
{
const int maxn = 12;

int n, m, edges[maxn][maxn], f[1 << maxn], d[maxn], ans = 1e9;

inline void addedge(int f, int t, int v)
{
	edges[f][t] = min(edges[f][t], v);
	edges[t][f] = min(edges[t][f], v);
}

inline void dfs(int k)
{
	for (int i = 0; i < n; ++i) if(k & (1 << i)) 
		for (int j = 0; j < n; ++j)
			if(!(k & (1 << j)) && f[k | (1 << j)] > f[k] + edges[i][j] * d[i] && edges[i][j] != 0x3f3f3f3f)
				f[k | (1 << j)] = f[k] + edges[i][j] * d[i], d[j] = d[i] + 1, dfs(k | (1 << j));
}

inline void solve()
{
	memset(edges, 0x3f, sizeof(edges));
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int f, t, v;
		cin >> f >> t >> v;
		addedge(f - 1, t - 1, v);
	}
	
	for (int i = 0; i < n; ++i)
	{
		memset(d, 0x3f, sizeof(d));
		memset(f, 0x3f, sizeof(f));
		d[i] = 1, f[1 << i] = 0, dfs(1 << i);
		ans = min(ans, f[(1 << n) - 1]);
	}

	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	baozang::solve();
	return 0;
}