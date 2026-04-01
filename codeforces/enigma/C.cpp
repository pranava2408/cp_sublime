#include <bits/stdc++.h>
#include <numeric>

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
	ll n, x; cin >> n >> x;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	ll su = accumulate(a.begin(), a.end(), 0ll);
	ll need = max(0ll, x - su);
	if (need == 0) {
		cout << 0 << "\n";
		return;
	}
	ll ans = 1e18;
	for (ll i = 1; i < n; i++) {
		// ll maxi = max(a[i], a[i - 1]);
		// ll mini = min(a[i], a[i - 1]);
		ll _1 = a[i - 1], _2 = a[i];
		ll cur = 0;
		ll step = 0;
		while (cur < need) {
			step ++;
			if (_1 >= _2) {
				_2 += _1;
				cur += _1;
			} else {
				_1 += _2;
				cur += _2;
			}
		}
		ans = min(ans, step);
	} cout << ans << "\n";
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