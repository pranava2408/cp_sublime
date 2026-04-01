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
	vector<ll> pref(n + 1, 0);
	for (ll i = 0; i < n; i++) {
		pref[i + 1] = max(pref[i], a[i]);
	}
	for (ll i = 1; i < n; i += 2) {
		a[i] = pref[i + 1];
	}
	debug(a);
	ll answer = (a[0] == a[1]);;
	for (ll i = 2; i < n; i += 2) {
		answer += max(0ll, a[i] - a[i - 1] + 1ll);
	} cout << answer << endl;
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