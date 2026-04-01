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

ll LCM(ll a, ll b) {
	return (a * b) / __gcd(a, b);
}

ll cnt(ll m, ll a, ll b, ll c) {
	if (b == c) {
		ll ans = (m / a) - (m / LCM(a , b));
		return ans;
	}
	ll ans = (m / a) - (m / LCM(a , b)) - (m / LCM(a , c)) + m / LCM(a , LCM( b , c));
	return ans;
}

void solve() {
	ll a, b, c, m; cin >> a >> b >> c >> m;
	ll val1 = LCM(a, b);
	ll val2 = LCM(a, c);
	ll val3 = LCM(b, c);
	ll val4 = LCM(val1, c);

	ll _2 = (m / val4);

	ll ans1 = cnt(m, a, b, c) * 6 + (cnt(m, val1, c, c) + cnt(m, val2, b, b)) * 3 + _2 * 2;
	// cout << ans1 << endl;
	ll ans2 = cnt(m, b, a, c) * 6 + (cnt(m, val1, c, c) + cnt(m, val3, a, a)) * 3 + _2 * 2;
	ll ans3 = cnt(m, c, b, a) * 6 + (cnt(m, val3, a, a) + cnt(m, val2, b, b)) * 3 + _2 * 2;
	cout << ans1 << " " << ans2 << " " << ans3 << endl;

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