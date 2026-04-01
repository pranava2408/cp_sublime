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
	ll last = -1;
	ll mothFuck = 0;
	for (ll i = 0; i < n; i++)if (a[i] == -1)last = i;
	if (a[0] == -1 && last == 0 ) {
		ll fuck = 0;
		for (ll i = 2; i < n; i++) {
			if (a[i] == -1) {
				a[i] = 0;
			}
			fuck += a[i] - a[i - 1];
		}


		if (fuck >= 0)a[0] = a[1];
		else {
			a[0] = max(0ll, a[1] + fuck);
		}
		fuck += a[1] - a[0];
		cout << abs(fuck) << '\n';
		for (auto pos : a)cout << pos << " ";
		cout << endl;
		return;
	}
	for (ll i = 0; i < n; i++) {
		if (a[i] == -1) {
			if (i != last)a[i] = 0;
			else {
				if (mothFuck <= 0 && i == n - 1)a[i] = a[i - 1] + abs(mothFuck);
				else a[i] = 0;
			}
		}
		if (i != 0) {
			mothFuck += (a[i] - a[i - 1]);
		}
	}
	cout << abs(mothFuck) << '\n';
	for (auto pos : a)cout << pos << ' ';
	cout << '\n';
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