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
	ll n , m, k; cin >> n >> m >> k;
	string str ; cin >> str;
	vector<vector<ll>> graph(n);
	while (m--) {
		ll u, v; cin >> u >> v;
		u--, v--;
		graph[u].emplace_back(v);
	}
	debug(graph);
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2*k + 1, vector<ll>(2, -1)));
	function<ll(ll, ll, ll)> dpval = [&](ll node, ll k , ll who)->ll{
		debug(node, k, who);
		if (dp[node][k][who] != -1)return dp[node][k][who];
		if (k == 0) {
			return dp[node][k][who] = (str[node] - 'A');
		}
		for (auto pos : graph[node]) {
			if (dpval(pos, k - 1, !who) == who) {
				return dp[node][k][who] = who;
			}
		}
		return dp[node][k][who] = !who;
	};
	cout << (dpval(0, 2*k, 0) ? "Bob" : "Alice") << endl;
	debug(dpval(1,1,1));
	
	// debug(dp);
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