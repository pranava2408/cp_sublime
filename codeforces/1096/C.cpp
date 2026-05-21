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
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (auto & pos : a)cin >> pos;

	for (ll i = 0; i < n; i++) {
		ll val = a[i] % 6;
		if (val == 0) {
			// ans.push_back(a[i]);
			cout << a[i] << " ";
		}
	}

	for (ll i = 0; i < n; i++) {
		ll val = a[i] % 6;
		if (val % 2 == 0 && val != 3 && val != 0) {
			cout << a[i] << " ";

			// cnt++;
		}
	}

	for (ll i = 0; i < n; i++) {
		ll val = a[i] % 6;
		if (val % 2 != 0 && val != 3) {
			// ans.push_back(a[i]);
			cout << a[i] << " ";
		}
	}








	for (ll i = 0; i < n; i++) {
		ll val = a[i] % 6;
		if (val == 3) {
			// ans.push_back(a[i]);
			cout << a[i] << " ";
			// cnt1++;
		}
	}


	cout << endl;


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