#include <bits/stdc++.h>
#include <stdlib.h>

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
	ll n , m, l, s, t; cin >> n >> m >> l >> s >> t;
	vector<pair<ll, ll>> graph[n + 1];
	for (ll j = 0; j < m; j++) {
		ll u, v, w; cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}

	set<ll> temp;
	function<void(ll, ll, ll)> dfs = [&](ll node, ll edges, ll cost)->void{
		if (cost > t || edges > l)return;

		if (cost >= s && edges == l)temp.insert(node);
		for (auto pos : graph[node]) {
			dfs(pos.first, edges + 1, cost + pos.second);
		}

	};
	dfs(1, 0, 0);
	for (auto pos : temp)cout << pos << " ";
	cout << "\n";
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