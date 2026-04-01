#include <bits/stdc++.h>
#include <climits>

#ifndef ONLINE_JUDGE
#include "debug.h"
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
	vector<ll> b(n);
	for (auto &pos : a)cin >> pos;
	for (auto &pos : b)cin >> pos;
	// vector<ll> dp(n + 1, 1e18);
	// vector<vector<ll>> dp1(n + 1, vector<ll>(n + 1, 1e18));
	vector<ll> prev(n + 1, 1e18);
	vector<ll> cur(n + 1, 1e18);

	a.push_back(LLONG_MAX);
	b.push_back(0);

	vector<ll> tot = a;
	sort(tot.begin(), tot.end());
	debug(tot);
	for (ll i = 0; i <= n; i++) {
		prev[i] = b[0];
	}
	for (ll i = 0; i <= n; i++) {
		if (a[0] == tot[i]) prev[i] = 0;
	}
	// dp[0] = 0;
	bool ck = true;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= n; j++)cur[j] = 1e18;
		// dp1[i][i] = min(dp1[i][i], dp1[i - 1][i]);
		ll mini = 1e18;
		for (ll j = 0; j <= n; j++) {
			// if (tot[j] >= a[i - 1] && ck) {
			// 	cur[j] = min(cur[j], (a[i] == tot[j] ? 0ll : b[i]));
			// }
			mini = min(mini, prev[j]);

			cur[j] = min(cur[j], mini + (a[i] == tot[j] ? 0ll : b[i]));

		}prev = cur;
		// ll mini = 1e18;
		// for (ll j = i - 2; j >= 0; j--) {
		// 	if (j != i - 2 && a[j + 1] > a[j + 2])break;
		// 	mini = min(mini, b[i] + dp1[j][j + 1]);
		// }
		// if (a[i] >= a[i - 1]) {
		// 	dp1[i][i] = min(dp1[i][i], mini - b[i]);
		// }
		// for (ll j = 0; j <= n; j++) {
		// 	if (a[j] >= a[i - 1]) {
		// 		dp1[i][j] = min(dp1[i][j], mini);
		// 	}
		// }
		// if (a[i] < a[i - 1])ck = false;

	} cout << prev[n] << endl;
	debug(a);
	// debug(dp1);
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