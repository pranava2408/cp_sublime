#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../../debug.h"
#else
#define debug(...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld long double

const ld eps = 1e-12;


void solve() {
	ll n , m; cin >> n >> m;
	vector<string> mat(n);
	for (auto &pos : mat)cin >> pos;
	vector<pair<ll, ll>> map[26];
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (mat[i][j] == '.' || mat[i][j] == '#')continue;
			map[mat[i][j] - 'a'].push_back({i, j});
		}
	}
	vector<vector<ll>> dist(n, vector<ll>(m, -1));
	dist[0][0] = 0;
	queue<pair<ll, ll>> bfs;
	bfs.push({0, 0});
	while (bfs.size()) {
		debug(dist);
		auto [u, v] = bfs.front();
		debug(u,v);
		bfs.pop();
		// for(ll j = )
		for (ll i = -1; i <= 1; i += 2) {
			if (u + i >= 0 && u + i < n && mat[u + i][v] != '#' && dist[u + i][v] == -1) {
				dist[u + i][v] = dist[u][v] + 1;
				bfs.push({u + i, v});
			}

			if (v + i >= 0 && v + i < m && mat[u][v + i] != '#' && dist[u][v + i] == -1) {
				dist[u][v + i] = dist[u][v] + 1;
				bfs.push({u, v + i});
			}
		}
		if (mat[u][v] != '.') {
			for (auto pos : map[mat[u][v] - 'a']) {
				if (dist[pos.first][pos.second] == -1) {
					dist[pos.first][pos.second] = dist[u][v] + 1;
					bfs.push({pos.first, pos.second});
				}
			}
			map[mat[u][v] - 'a'].clear();
		}
	}
	cout<<dist[n-1][m-1]<<'\n';
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif
	int tt = 1;
	// cin >> tt;
	while (tt--)
		solve();
}