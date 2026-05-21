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

	ll low = 0;
	ll high  = 1e15;
	ll ans = high;
	auto ck = [&](ll mid)->bool{
		ll charge = mid;
		ll idx = -1;
		for (ll i = 0; i < n; i++) {
			charge += a[i];
			if (charge < 0) {
				idx = i;
				break;
			}
			charge = min(charge, mid);
		}

		if (idx == -1)return true;
		vector<ll> maxi(idx + 1, -1e18);
		maxi[idx] = a[idx];
		for (ll i = idx - 1; i >= 0; i--) {
			maxi[i] = max(maxi[i + 1], 0ll)	 + a[i];
			// maxi[i] = min(maxi[i], mid);
		}
		ll can = abs(a[idx]);
		ll cur = mid;
		for (ll j = 0; j < idx; j++) {
			cur += a[j];
			cur = min(cur, mid);
			if (a[j] < 0) {
				ll nex = maxi[j + 1];
				ll prev = max(nex + cur, mid);
				ll tot = max(prev + abs(a[j]), mid);
				can = max(can, tot - prev);
			}
		}


		charge += can;
		charge = min(charge, mid);

		for (ll i = idx + 1; i < n ; i++) {
			charge += a[i];
			charge = min(charge, mid);
			if (charge < 0) {
				return false;
			}
		}
		return true;
	};
	while (low <= high) {
		ll mid = (low + high) >> 1;

		if (ck(mid)) {
			ans = mid;
			high = mid - 1;
		} else low = mid + 1;
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
	cin >> tt;
	while (tt--)
		solve();
}