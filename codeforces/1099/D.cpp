#include <bits/stdc++.h>
#include <type_traits>

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

// bool ck = true;

void solve() {
	ll n ;
	cin >> n;
	string str;
	cin >> str;

	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;

	vector<ll> c(n);
	for (auto &pos : c)cin >> pos;
	for (ll i = 1; i < n; i++) {
		if (c[i] < c[i - 1]) {
			cout << "No\n";
			return;
		}
	}

	ll L = 0, R = 0;
	debug(str, a, c);
	ll idx = -1;
	for (ll i = 0; i < n; i++) {
		if (str[i] == '1') {
			L += a[i];
			R += a[i];

			if (i == 0 || c[i] > c[i - 1]) {
				if (c[i] >= L && c[i] <= R) {
					ll prev = R;
					L = c[i], R = c[i];
					if (idx != -1)
						a[idx] -= (prev - c[i]);
				}
				else {
					cout << "No\n";
					return;
				}
				idx = -1;
			} else {
				if (L <= c[i]) {
					ll prev = R;
					R = min(R, c[i]);
					if (idx != -1)
						a[idx] -= (prev - R);
				}
				else {
					cout << "No\n";
					return;
				}
				// idx = -1;
			}
		} else {
			if (i == 0 || c[i] > c[i - 1]) {
				a[i] = c[i] - R;
				L = c[i], R = c[i];
				idx = -1;
			} else {
				idx = i;
				a[i] = c[i] - R;
				L -= 1e13;
				R = c[i];
			}
		}
		if (L > R) {
			cout << "No\n";
			return;
		}
	}


	cout << "Yes\n";

	for (auto &pos : a)cout << pos << " ";

	cout << "\n";

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

	// while (ck)solve();
}