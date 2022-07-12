#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > graph;
vector<int> dfn, low;
vector< pair<int, int> > result;
int dep;

void dfs(int cur, int par)
{
	int child = 0;
	dfn[cur] = low[cur] = ++dep;

	for (auto& i : graph[cur]) {

		if (!dfn[i]) {
			++child;
			dfs(i, cur);
			low[cur] = min(low[cur], low[i]);
		}
		else {
			if (i != par) low[cur] = min(low[cur], dfn[i]);
			continue;
		}

		if (low[i] >= dfn[cur] && (par != -1 || child >= 2)) ++result[cur].second;
	}
}

int cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.second == b.second ? a.first < b.first : a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	while (cin >> n >> m, n && m) {

		// init
		graph.assign(n, vector<int>());
		dfn.assign(n, 0);
		low.assign(n, 0);
		result.clear();
		for (int i = 0; i < n; ++i) result.push_back(pair<int, int>(i, 1));
		dep = 0;

		// build graph
		int a, b;
		while (cin >> a >> b, a != -1 && b != -1) {
			graph[a].emplace_back(b);
			graph[b].emplace_back(a);
		}

		// find articulation point
		for (int i = 0; i < n; ++i) if (!dfn[i]) dfs(i, -1);

		// sort
		sort(result.begin(), result.end(), cmp);

		for (int i = 0; i < m; ++i) cout << result[i].first << " " << result[i].second << "\n";
		cout << "\n";
	}

	return 0;
}