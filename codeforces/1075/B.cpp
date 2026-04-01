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
	ll n, x; cin >> n >> x;
	vector<vector<ll>> a(n, vector<ll>(3));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 3; j++)cin >> a[i][j];
	}
	ll dis = 0;
	for (ll i = 0; i < n; i++)dis += (a[i][0] * (a[i][1] - 1));
	ll ans = -1;

	if (dis >= x) {
		// cout << "this";
		cout << 0 << "\n";
		return;
	}
	ll need =  x - dis;
	ll maxi = 0;
	for (ll i = 0; i < n; i++) {
		maxi = max(maxi, a[i][0] * a[i][1] - a[i][2]);
	}
	if (maxi == 0) {
		cout << -1 << "\n";
		return;
	}
	// cout << maxi << "\n";
	// cout << need << " n" << maxi << "\n";
	cout << (need + maxi - 1) / maxi << "\n";

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