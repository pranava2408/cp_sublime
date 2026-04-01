#include <bits/stdc++.h>
#include <chrono>
#include <climits>
#include <utility>

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
	vector<ll> graph[n + 1];
	while (m--) {
		ll  u, v ; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	queue<ll> bfs;


	auto BFS = [&]()->pair<vector<ll>, vector<ll>> {
		vector<ll> dist(n + 1, -1);
		vector<ll> par(n + 1, -1);
		while (bfs.size()) {
			auto node = bfs.front();
			if (dist[node] == -1)dist[node] = 0;
			ll baap = par[node] == -1 ? node : par[node];
			bfs.pop();
			for (auto pos : graph[node]) {
				if (dist[pos] == -1) {
					dist[pos] = dist[node] + 1;
					par[pos] = baap;
					bfs.push(pos);
				}
			}
		}
		return make_pair(dist, par);

	};

	string str; cin >> str;
	for (ll i = 0; i < n; i++) {
		if (str[i] == 'S')
		{
			bfs.push(i + 1);
		}
	}

	auto jus = BFS();


	set<ll> whole;
	for (ll i = 1; i <= n; i++)whole.insert(i);
	for (auto pos : jus.second) {
		whole.erase(pos);
	}

	for (auto pos : whole)bfs.push(pos);

	auto jus1 = BFS();


	vector<ll> mini = jus.first;
	auto secondMini = jus1.first;
	for (ll i = 1; i <= n; i++) {
		if (secondMini[i] == -1)secondMini[i] = LLONG_MAX;
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