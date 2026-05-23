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
	// bool op = true;
	// bool nop = true;

	// for (ll i = 1; i < n; i++) {
	// 	bool curop = false, curnop = false;
	// 	if (op && a[i] >= (a[i - 1] + k)) {
	// 		curnop = true;
	// 	}
	// 	if (op && (a[i] + k) >= (a[i - 1] + k)) {
	// 		curop = true;
	// 	}

	// 	if (nop && a[i] >= a[i - 1]) {
	// 		curnop = true;
	// 	}

	// 	if (nop && (a[i] + k) >= a[i - 1]) {
	// 		curop = true;
	// 	}

	// 	op = curop;
	// 	nop = curnop;
	// }


	// cout << ((op || nop) ? "Yes" : "No") << "\n";
	ll k = 0;
	for (ll i = 0; i < n - 1; i++) {
		k = max(k, a[i] - a[i + 1]);
	}

	for (ll i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			a[i] += k;
		}

		if (a[i] < a[i - 1]) {
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
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