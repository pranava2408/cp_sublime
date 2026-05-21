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
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1e18));
	for (ll j = 0; j <= n; j++) {
		dp[j][0] = 0;
	}
	vector<ll> maxi(k + 1, -1e18);
	vector<ll> maxi1(k + 1, -1e18);
	for (ll i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		ll val = a[i - 1];
		for (ll j = 1; j <= k; j++) {
			dp[i][j] = max(dp[i][j], val + maxi[j - 1]);
			dp[i][j] = max(dp[i][j], -val + maxi1[j - 1]);
		}

		for (ll j = 0; j <= k; j++) {
			maxi[j] = max(maxi[j], dp[i-1][j] - val);
			maxi1[j] = max(maxi1[j], val + dp[i-1][j]);
		}
		

		debug(dp[i]);
		debug(maxi);
		debug(maxi1);
	}
	// cout << dp[3][1] << endl;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= k; j++)ans = max(ans, dp[i][j]);
	}
	cout << ans << endl;
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