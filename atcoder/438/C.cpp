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
	vector<ll> a(n), b(n), c(n);
	for (auto &pos : a)cin >> pos;
	for (auto & pos : b)cin >> pos;
	for (auto &pos : c)cin >> pos;
	vector<ll> dp(n, -1e18);
	dp[n - 2] = b[n - 2] + c[n - 1];
	ll sum = c[n - 1] + c[n - 2];
	for (ll i = n - 3; i >= 0; i--) {
		dp[i] = dp[i + 1] + b[i];
		dp[i] = max(dp[i], b[i] + sum);
		sum += c[i];
	}
	ll ans = -1e18;
	sum = 0;
	for (ll i = 0; i <= n - 3; i++) {
		sum += a[i];
		ans = max(ans, sum + dp[i + 1]);
	}
	cout << ans << "\n";


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