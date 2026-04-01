#include <algorithm>
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
	ll n, q; cin >> n >> q;
	vector<ll> temp(n);
	for (auto &pos : temp)cin >> pos;
	sort(temp.begin(), temp.end());

	while (q--) {
		ll x, y; cin >> x >> y;


		ll low = x, high = max(temp.back(), x) + y + 1;
		ll ans = 1e18;
		ll left = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
		while (low <= high) {
			debug(ans);
			ll mid = (low + high) >> 1;
			ll cnt = upper_bound(temp.begin(), temp.end(), mid) - temp.begin();
			cnt -= left;
			ll have = mid - x + 1 - cnt;
			debug(mid, have);
			if (have >= y) {
				ans = mid;
				high = mid - 1;
			} else low = mid + 1;
		}
		cout << ans << "\n";
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