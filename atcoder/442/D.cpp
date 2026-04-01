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
	vector<ll> prefix(n + 1, 0);
	for (ll i = 0; i < n; i++)prefix[i + 1] = prefix[i] + a[i];
	while (q--) {
		ll type ; cin >> type;
		if (type == 1) {
			ll idx; cin >> idx;
			idx --;
			swap(a[idx], a[idx + 1]);
			prefix[idx + 1] = prefix[idx] + a[idx];
			prefix[idx + 2] = prefix[idx +	1] + a[idx + 1];
		}
		else {
			ll l, r; cin >> l >> r;
			l--;
			cout << prefix[r] - prefix[l] << "\n";
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