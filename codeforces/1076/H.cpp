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
	vector<ll> vals(n);
	for (auto &pos : vals)cin >> pos;
	for (auto &pos : vals) pos = (pos & 1);
	vector<ll> graph[n];
	for (ll i = 0; i < n - 1; i++) {
		ll u, v; cin >> u >> v;
		u--, v--;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	vector<ll> par(n, -1);
	par[0] = 0;
	function<void(ll)> dfs = [&] (ll node)->void{
		for (auto pos : graph[node]) {
			if (par[pos] == -1) {
				par[pos] = node ;
				dfs(pos);
			}
		}
	};
	dfs(0);


	vector<vector<ll>> dp(n, vector<ll>(2, -1));

	function<ll(ll, ll)> dpval = [&](ll i, ll j)->ll{
		// cout<<i<<" "<<j
		if (dp[i][j] != -1)return dp[i][j];
		ll cursum = 0;
		if (j) {
			cursum ^= vals[par[i]];
		}



		ll both = 0;
		for (auto pos : graph[i]) {
			if (pos != par[i]) {
				// these will be children
				// how can we solve ?
				ll ck = 1;
				for (ll j = 0; j < 2; j++) {
					ck &= dpval(pos, j);
				}
				both += ck * vals[pos];

				if (!ck) {
					if (dpval(pos, 0)) {
						cursum ^= vals[pos];
					} else if (dpval(pos, 1)) {

					}
					else return dp[i][j] = 0;
				}
			}
		}



		if (both > 0)return dp[i][j] = 1;


		return dp[i][j] = (cursum ^ vals[i]);

	};
	debug(vals);

	for (ll i = 0; i < n; i++)for (ll j = 0; j < 2; j++)debug(dpval(i, j));


	// cout << (dpval(0, 0) ? "YES" : "NO") << "\n";


	if (dpval(0, 0) == 0) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	function<void(ll, ll)> path = [&](ll i, ll j)->void{
		debug(i, j);
		ll cursum = 0;
		if (j) {
			cursum ^= vals[par[i]];
		}

		ll both = 0;
		vector<ll> bo;
		vector<ll> left;
		vector<ll> oo;
		for (auto pos : graph[i]) {
			if (pos != par[i]) {
				debug(pos);
				ll ck = 1;
				for (ll j = 0; j < 2; j++) {
					ck &= dpval(pos, j);
				}
				both += ck * vals[pos];
				if (ck) {
					if (vals[pos])
						bo.push_back(pos);
					else left.push_back(pos);
				}

				if (!ck) {
					if (dpval(pos, 0)) {
						left.push_back(pos);
						cursum ^= vals[pos];
					} else if (dpval(pos, 1)) {
						path(pos, 1);
					}
				}
			}
		}


		debug(i, j, bo, left);





		if (both > 0) {
			if (cursum ^ vals[i]) {
				for (auto pos : bo)path(pos, 1);
				cout << i + 1 << " ";
				for (auto pos : left)path(pos, 0);
				return;
			}

			ll len = bo.size();

			for (ll i = 1; i < len; i++)path(bo[i], 1);
			cout << i + 1 << " ";
			for (auto pos : left) path(pos, 0);
			path(bo[0], 0);
			return;
		}

		cout << i + 1 << " ";
		for (auto pos : left)path(pos, 0);
		// cout << " ";
	};
	path(0, 0);
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
	cin >> tt;
	while (tt--)
		solve();
}