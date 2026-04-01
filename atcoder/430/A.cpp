#include <bits/stdc++.h>
#include <climits>
#include <functional>

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
	set<ll> have;
	have.insert(0);
	ll ans = LLONG_MAX;

	map<ll, ll> value;
	value[0] = LLONG_MAX;
	for (ll i = 0; i < n; i++) {
		ll cur = LLONG_MAX;
		auto it = have.upper_bound(a[i]);
		if (it != have.end()) {
			cur = min(cur, *it - a[i]);

			if (value[*it] > cur) {
				ans -= value[*it];
				value[*it] = cur;
				ans += value[*it];
			}
		}
		if (it != have.begin())
			it --;
		if (a[i] >= *it) {
			cur = min(cur, a[i] - *it);
			if (a[i] - *it <= value[*it]) {
				ans -= value[*it];
				value[*it] = a[i] - *it;
				ans += value[*it];

			}
		}
		ans += cur;
		value[a[i]] = cur;
		cout << ans << "\n";
		debug(cur);
		have.insert(a[i]);
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