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
	vector<ll> b(n);
	for (auto &pos : b)cin >> pos;
	vector<ll> tem(n);
	tem[0] = __gcd(a[0], a[1]);
	tem[n - 1] = __gcd(a[n - 1], a[n - 2]);
	for (ll i = 1; i < n - 1; i++) {
		tem[i] = lcm(__gcd(a[i], tem[i - 1]), __gcd(a[i], a[i + 1]));
	}
	vector<ll> mult(n, -1);
	vector<ll> done(n, -1);
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		if (tem[i] <= b[i]) {
			ans ++;
			mult[i] = b[i] / tem[i];
			// if (mult[i] > 1 || tem[i] != a[i])ans++;
		}
		else done[i] = a[i] / tem[i];
	}

	for (ll i = 1; i < n - 1; i++) {
		if (done[i] == -1) {
			if (done[i - 1] == 1 && done[i + 1] == 2 && mult[i] == 2) {
				ans--;
				continue;
			}
			if (done[i - 1] == 2 && done[i + 1] == 1 && mult[i] == 2) {
				ans--;
				continue;
			}
		}
	}

	cout << ans << "\n";

	// debug(a, b, mult);
	debug(mult,done);
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