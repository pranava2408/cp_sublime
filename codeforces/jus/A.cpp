#include <bits/stdc++.h>
#include <climits>
#include <queue>

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
	ll n , m, k, s, d; cin >> n >> m >> k >> s >> d;
	debug(n, m, k, s, d);
	vector<pair<ll, ll>> graph[n];
	for (ll i = 0; i < m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);
	}
	// debug(graph,n);
	for (int i = 0; i < n; i++) {
		debug(graph[i]);
	}

	vector<vector<ll>> dist(n, vector<ll>(k + 1, LLONG_MAX));

	dist[s][0] = 0;
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

	pq.push({0, s, 0});

	while (pq.size()) {
		auto tp = pq.top();
		debug(tp);

		pq.pop();
		if (dist[tp[1]][tp[2]] < tp[0]) {
			continue;
		}

		for (auto &pos : graph[tp[1]]) {
			// we use
			ll cos = tp[2] + 1;
			if (cos <= k && tp[0] < dist[pos.first][cos]) {
				dist[pos.first][cos] = tp[0];
				pq.push({dist[pos.first][cos], pos.first, cos});
			}
			// we don't use

			if (tp[0] + pos.second < dist[pos.first][tp[2]]) {
				dist[pos.first][tp[2]] = tp[0] + pos.second;
				pq.push({dist[pos.first][tp[2]], pos.first, tp[2]});
			}

		}
	}


	ll ans = LLONG_MAX;
	for (ll i = 0; i <= k; i++) {
		ans = min(ans, dist[d][i]);
	}
	cout << (ans ==LLONG_MAX ? -1 : ans) << "\n";
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
	cin >> tt;
	while (tt--)
		solve();
}