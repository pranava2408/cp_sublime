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
	ll n, m; cin >> n >> m;
	vector<ll>conflict(n, 0);
	for (ll i = 0; i < m; i++) {
		ll a, b; cin >> a >> b;
		a--, b--;
		conflict[a]++;
		conflict[b]++;
	}
	debug(conflict);
	for (ll i = 0; i < n; i++) {
		ll left = n - 1 - conflict[i];
		if (left >= 3) {
			ll ans = left * (left - 1) * (left - 2);
			ans /= 6;
			cout << ans << " ";
		} else {
			cout << 0 << " ";
		}
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