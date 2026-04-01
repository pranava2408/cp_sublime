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
	auto query = [&](ll i, ll j)->ll{
		cout << "? " << i << " " << j << endl;
		ll val; cin >> val;
		return val;
	};

	ll cnt = n - 2;
	ll i = 3;
	while (cnt) {
		ll va = query(i, 2 * n - i + 1);
		if (va) {
			cout << "! " << i << endl;
			return;
		}
		i ++;
		cnt --;
	}


	ll va = query(1, 2 * n);
	ll va1 = query(1, 2 * n - 1);

	if (va) {
		cout << "! " << 1 << endl;
		return;
	}
	if (va1) {
		cout << "! " << 1 << endl;
		return;
	}

	ll va2 = query(2 * n, 2 * n - 1);


	if (va2) {
		cout << "! " << 2 * n << endl;
		return;
	}
	cout << "! " << 2 << endl;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
// 	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
// 	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
// #endif
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}