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
	for (auto &pos : a)cin >> pos;

	// ll cur = 0;
	// ll ans = 0;
	// for (ll i = 0; i < n; i++) {
	// 	ll val; cin >> val;
	// 	if (cur >= 0) {
	// 		cur -= val;
	// 		ans += (cur < 0);
	// 	} else {
	// 		cur += val;
	// 		ans += (cur >= 0);
	// 	}
	// }
	// cout << ans << endl;
	ll ans = 0;
	for (ll i = 0; i < (1LL << n); i++) {
		ll cur = 0;
		ll dis = 0;
		for (ll j = 0; j < n; j++) {
			ll sign = dis >= 0 ? 1 : -1;

			if (i & (1LL << j)) {
				dis += (a[j]);
			} else {
				dis -= a[j];
			}


			ll nexsign = dis >= 0 ? 1 : -1;

			if (sign * nexsign < 0) {
				cur ++;
			}

		}

		ans = max(ans, cur);
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
	// cin >> tt;
	while (tt--)
		solve();
}