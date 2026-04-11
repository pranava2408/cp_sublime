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
	ll n, m, a, b; cin >> n >> m >> a >> b;
	debug(n, m, a, b);
	// if (n == 1 && m == 1) {
	// 	cout << "Yes\n";
	// 	return;
	// }
	// if (n % a == 0 && a != 1) {
	// 	cout << "No\n";
	// 	return;
	// }
	// if (m % b == 0 && b != 1) {
	// 	cout << "No\n";
	// 	return;
	// }

	ll gc1 = __gcd(n, a);
	ll gc2 = __gcd(m, b);

	if (gc1 != 1 || gc2 != 1) {
		cout << "No\n";
		return;
	}

	a %= n;
	b %= m;

	// ll val = ((n / a + 1) * a) % n  + 1;
	// ll val1 = ((n / b + 1) * b) % m + 1;

	// if (val == 1 && val1 == 1) {
	// 	cout << "No\n";
	// 	return;
	// }
	// cout << "Yes\n";
	ll gc = __gcd(n, m);
	ll lc = n * m;
	lc /= gc;

	ll vis = 2 * lc;

	if (vis < n * m) {
		cout << "No\n";
		return;
	}

	debug(vis, n * m);

	cout << "Yes\n";



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