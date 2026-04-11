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
	ll n , k; cin >> n >> k;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)cin >> a[i];
	debug(a);
	// ll val; cin >> val;
	// val --;
	vector<ll> idx;
	while (k--) {
		ll temp; cin >> temp;
		idx.push_back(temp);
	}
	debug(idx);
	// ll idx = 0;
	// while (idx < n && a[idx] == a[val])idx++;
	// debug(idx);
	// ll prev = !a[val];
	// ll ans = 0;
	// for (ll i = idx + 1; i < n; i++) {
	// 	if (a[i] != prev) {
	// 		debug(i);
	// 		prev = a[i];
	// 		ans ++;
	// 	}
	// }

	// cout << ans << "\n";
	// ll left = 0;
	// for (ll i = val - 1; i >= 0; i--) {
	// 	if (a[i] != a[i + 1]) {
	// 		if (a[i] != a[val])
	// 			left ++;
	// 	}
	// }
	// ll right = 0 ;
	// for (ll i = val + 1; i < n; i++) {
	// 	if (a[i] != a[i - 1]) {
	// 		if (a[i] != a[val])
	// 			right ++;
	// 	}
	// }

	// debug(left, right);
	// cout << (max(left, right) << 1) << "\n";


	set<ll> temp(idx.begin(), idx.end());


	ll ans = 1e18;

	ll flips = 0;
	for (ll i = 1; i < n; i++) {
		if (a[i] != a[i - 1])flips ++;
	}

	ll cur = 0;
	for (ll i = 0; i < n; i++) {
		if (i != 0 && a[i] != a[i - 1])cur++;

		if (temp.count(i + 1)) {
			ll right = flips  - cur;

			ans = min(ans, max((cur - (cur % 2 == 0)) * 2, (right - (right % 2 == 0)) * 2));
			// ans = min(ans, );
		}

	}
	cout << max(ans, 0ll) << "\n";
	
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