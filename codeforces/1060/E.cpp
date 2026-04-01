#include <algorithm>
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
	vector<ll> graph[n + 1];
	for (ll i = 0; i < n - 1; i++) {
		ll u , v; cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}


	vector<ll> parent(n + 1, -1);

	vector<ll> dist(n + 1, 0);

	dist[1] = 0;

	function<void(ll)> dfs = [&](ll node)->void{

		for (auto pos : graph[node]) {
			if (pos != parent[node]) {
				dist[pos] = dist[node] + 1;
				parent[pos] = node;
				dfs(pos);
			}
		}
	};
	dfs(1);


	ll val = n ;

	vector<ll> path;
	// path.emplace_back(val);
	vector<bool> inPath(n + 1, false);
	inPath[n] = true;
	while (val != 1) {
		val = parent[val];
		inPath[val] = true;
		path.emplace_back(val);
	}

	vector<vector<ll>> answer ;


	ll tot = 0;

	function<void(ll)> getAns = [&](ll node)->void{
		debug(node);
		if (graph[node].size() != 1 || node == 1) {

			for (auto pos : graph[node]) {
				if (pos != parent[node]) {
					getAns(pos);
				}
			}
		}

		if (inPath[node])return;


		if ((tot % 2) == (dist[node] % 2)) {
			answer.push_back({1});
			tot ++;
		}

		answer.push_back({2, node});

		answer.push_back({1});
		tot ++;

	};
	getAns(1);


	reverse(path.begin(), path.end());
	debug(path);

	for (auto pos : path) {
		if ((tot % 2) == (dist[pos] % 2)) {
			answer.push_back({1});
			tot ++;
		}

		answer.push_back({2, pos});

		answer.push_back({1});
		tot ++;
	}

	cout << answer.size() << endl;
	for (auto pos : answer) {
		for (auto posi : pos) {
			cout << posi << " ";
		} cout << endl;
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
	cin >> tt;
	while (tt--)
		solve();
}