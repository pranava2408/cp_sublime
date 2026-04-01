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
	ll even = -1;
	for (ll i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			if (even != -1) {
				cout << even << ' ' << a[i] << '\n';
				return;
			} even = a[i];
		}
	}
	// cout<<-1<<'\n';
	vector<ll> odd;

	for (ll i = 0; i < n; i++) {
		debug(odd);
		ll len = odd.size();
		for (ll j = len - 1; j >= 0; j--) {
			if ((a[i] % odd[j])%2 == 0) {
				cout << odd[j] << ' ' << a[i] << '\n';
				return;
			}
		}
		if (a[i] % 2 == 1)odd.push_back(a[i]);
	}
	cout<<-1<<'\n';


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