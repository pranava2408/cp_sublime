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
	ll n, m; cin >> n >> m;
	vector<ll> graph[n + 1];
	for (ll i = 0; i < m; i++) {
		ll u, v; cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}

	vector<bool> vis(n + 1, false);
	vector<ll> status(n + 1, -1);
	ll answer = 0;
	for (ll i = 1; i <= n; i++) {
		if (!vis[i]) {
			bool ck = false;
			vis[i] = true;
			status[i] = 1;
			queue<ll> bfs;
			bfs.push(i);
			ll ans = 0;
			ll cnt = 0;
			while (bfs.size()) {
				cnt++;
				ll val = bfs.front();
				bfs.pop();
				ll value = status[val];
				ans += value;
				for (auto pos : graph[val]) {
					if (status[pos] == value) {
						ck = true;
					}
					else {
						status[pos] = !value;
					}
					if (!vis[pos]) {
						vis[pos] = true;
						bfs.push(pos);
					}
				}
			}

			if (ck)continue;
			answer += max(ans, cnt - ans);

		}
	}
	cout << answer << endl;
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