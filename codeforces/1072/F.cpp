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
	vector<ll> graph[n];
	for (ll i = 0; i < n - 1; i++) {
		ll u , v; cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<ll> parent(n, -1);
	vector<ll> visited(n, 0);

	function<void(ll)> dfs = [&](ll node)->void{
		visited[node] = 1;
		for (auto pos : graph[node]) {
			if (!visited[pos]) {
				parent[pos] = node;
				dfs(pos);
			}
		}
	};
	dfs(0);

	vector<vector<ll>> dp(n, vector<ll>(3, -1));

	function<ll(ll, ll)> dpval = [&](ll i, ll j)->ll{
		// if (j == 1)return dp[i][j] = 1;
		if (dp[i][j] != -1)return dp[i][j];
		vector<ll> cur(3, 0);
		cur[0] = 1 ;
		ll cnt = 0;
		for (auto pos : graph[i]) {
			if (pos != parent[i]) {
				cnt ++;
				// cur[0] = 1;
				vector<ll> oth(3, 0);
				for (ll j = 0; j < 3; j++) {
					if (dpval(pos, j) == 1) {
						for (ll k = 0; k < 3; k++) {
							if (cur[k]) {
								ll nex = (k + j) % 3;
								oth[nex] = 1 ;
							}
						}

					}
				}
				cur = oth;
			}


		}
		if (cnt == 0)cur[0] = 0;
		cur[1] = 1;
		dp[i] = cur;
		return dp[i][j];
	};

	cout << (dpval(0, 0) == 1 ? "YES\n" : "NO\n");
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