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
	for (auto & pos : a)cin >> pos;
	vector<vector<ll>> dp(n + 1, vector<ll>(2, -1e18));
	dp[0][0] = 0;
	dp[1][0] = a[0];
	dp[1][1] = a[0];
	for (ll i = 2; i <= n; i++) {
		dp[i][1] = max(dp[i - 1][1] - a[i - 1], dp[i - 1][0] + a[i - 1]);
		dp[i][0] = max(dp[i - 1][0] + a[i - 1], dp[i - 1][1] - a[i - 1]);
	}
	debug(dp);


	ll answer = -1e18;
	ll suff = 0;
	for (ll i = n - 1; i >= 0; i--) {
		answer = max(answer,  dp[i][0] - suff);
		suff += a[i];
	}
	cout << answer << "\n";
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