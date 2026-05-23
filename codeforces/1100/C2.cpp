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
	ll n; cin >> n;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	vector<ll> pref(n + 1, 0);
	for (ll i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + abs(a[i]);
	}
	ll ans = accumulate(a.begin(), a.end(), 0ll);
	ll sum = 0;
	ll idx = -1;
	for (ll i = n - 1; i >= 0; i--) {
		if (a[i] > 0) {
			ll cur =  sum + pref[i] - a[i];
			if (cur > ans) {
				ans = cur;
				idx = i;
			}
		}
		sum += a[i];
	}
	vector<ll> ops;
	ll sign = 1;
	for (ll i = idx - 1; i >= 0; i--) {
		if (a[i] * sign > 0) {
			ops.push_back(i + 1);
			sign *= (-1);
		}
	}
	if (idx != -1) {
		ops.push_back(idx + 1);
	}
	cout << ops.size() << "\n";
	for (auto &pos : ops) {
		cout << pos << ' ';
	}
	cout << "\n";
	// cout << ans << "\n";
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