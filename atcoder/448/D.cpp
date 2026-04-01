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
	ll n; cin >> n;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	vector<vector<ll>> graph(n);
	for (ll i = 0; i < n - 1; i++) {
		ll u, v; cin >> u >> v;
		u--, v--;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	vector<ll> ans(n, -1);
	map<ll, ll> cnt;
	ll sum = 0;
	function<void(ll)>dfs = [&](ll node) {
		debug(node);
		cnt[a[node]]++;
		if (cnt[a[node]] == 2)sum ++;

		ans[node] = sum;


		for (auto pos : graph[node]) {
			if (ans[pos] == -1) {
				dfs(pos);
			}
		}


		cnt[a[node]]--;
		if (cnt[a[node]] == 1)sum--;
	};
	dfs(0);
	for (auto pos : ans) {
		cout << (pos ? "Yes\n" : "No\n");
	}

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