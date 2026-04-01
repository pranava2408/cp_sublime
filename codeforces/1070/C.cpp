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
	sort(a.begin(), a.end());
	vector<ll> odd, even;
	for (ll i = 0; i < n; i++) {
		if (a[i] & 1) {
			odd.push_back(a[i]);
		} else even.push_back(a[i]);
	}
	// ll ans = 0;
	if (odd.size() == 0) {
		for (ll i = 1; i <= n; i++) {
			cout << "0 ";
		} cout << "\n";
		return;
	}
	ll sum  = accumulate(a.begin(), a.end(), 0ll);
	ll ans = odd.back();
	// ll idx = even.size() - 1;
	ll idx = 0;
	reverse(even.begin(), even.end());
	cout << ans << " ";
	bool ck = false;
	for (ll i = 2; i <= n; i++) {
		if (idx < even.size()) {
			ans += even[idx];
			idx++;
			cout << ans << " ";
		} else {
			if (i == n && sum % 2 == 0) {
				cout << 0 << " ";
			} else if (!ck) {
				if (even.size() == 0) {
					cout << 0 << " ";
					ck = true;
					continue;
				}
				cout << (ans - even.back()) << " ";
				ck = true;
			} else {
				cout << ans << " ";
				ck = false;
			}
		}
	} cout << "\n";
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