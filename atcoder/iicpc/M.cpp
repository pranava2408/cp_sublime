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
	string a, b; cin >> a >> b;
	ll n = a.size();
	vector<ll> prev(2, 1e18);
	prev[0] = 0;
	for (ll i = 0; i < n; i++) {
		vector<ll> cur(2, 1e18);
		// if(str[i])
		ll val = a[i] - '0';
		ll val1 = b[i] - '0';
		// if (val) {
		// 	if(val1){
		// 		cur[1] = min(cur[1],prev[0]);
		// 		cur[0] = min(cur[0],prev[])
		// 	}
		// } else {

		// }
		for (ll j = 0; j < 2; j++) {
			for (ll k = 0; k < 2; k++) {
				for (ll x = 0; x < 2; x++) {
					ll va = j + k;
					va %= 2;
					ll cnt = (val != k) + (val1 != x);
					if (x == va) {
						cur[va] = min(cur[va], prev[j] + cnt);
					}
				}
			}
		}
		prev = cur;
	}

	cout << min(prev[0], prev[1]) << "\n";
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