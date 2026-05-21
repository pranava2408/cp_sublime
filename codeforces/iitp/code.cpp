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
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	stack<ll> st;
	vector<ll> idx(n, -1);
	for (ll i = 0; i < n; i++) {
		while (st.size() && a[st.top()] <= a[i]) {
			st.pop();
		}
		if (st.size()) {
			idx[i] = st.top();
		}
		st.push(i);
	}

	vector<ll> idx1(n, n );
	stack<ll> st1;
	for (ll i = n - 1; i >= 0; i--) {
		while (st1.size() && a[st1.top()] <= a[i]) {
			st1.pop();
		}
		if (st1.size()) {
			idx1[i] = st1.top();
		}
		st1.push(i);
	}

	vector<ll> pref(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + (i - 1 - idx[i - 1]) * (idx1[i - 1] - i + 1);

	}

	debug(idx1, idx);
	debug(pref);

	while (q--) {
		ll l, r; cin >> l >> r;
		cout << (pref[r] - pref[l - 1]) << endl;
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