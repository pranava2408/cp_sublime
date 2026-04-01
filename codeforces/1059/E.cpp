#include <bits/stdc++.h>
#include <ostream>

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
	ll n , k; cin >> n >> k;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	vector<bool> have(n + 1, false);
	for (auto pos : a)have[pos] = true;
	ll F = -1, S = -1, L = -1;
	for (ll i = 1; i <= n; i++) {
		if (!have[i]) {
			if (F == -1)F = i;
			else if (S == -1) {
				S = i;
			} else {
				L = i;
				break;
			}
		}
	}


	if (F == -1) {
		for (ll i = 0; i < k; i++) {
			cout << a[i] << " ";
		} cout << endl; return;
	}
	if (L != -1) {
		for (ll i = 0; i < k; i++) {
			if (i % 3 == 0)cout << F << " ";
			else if (i % 3 == 1)cout << S << " ";
			else cout << L << " ";
		} cout << endl;
		return;
	}
	if (S != -1) {
		L = a[0];
		for (ll i = 0; i < n; i++) {
			if (a[i] != a[n - 1]) {
				L = a[i];
				break;
			}
		}



		for (ll i = 0; i < k; i++) {
			if (i % 3 == 0)cout << F << " ";
			else if (i % 3 == 1)cout << S << " ";
			else cout << L << " ";
		} cout << endl;
		return;
	}


	for (ll i = 0; i < n; i++) {
		if (a[i] != a[n - 1]) {
			S = a[i];
			break;
		}
	}
	L = a[n - 1];


	for (ll i = 0; i < k; i++) {
		if (i % 3 == 0)cout << F << " ";
		else if (i % 3 == 1)cout << S << " ";
		else cout << L << " ";
	} cout << endl;
	return;


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