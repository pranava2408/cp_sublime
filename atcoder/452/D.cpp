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
	string s, t; cin >> s >> t;
	ll n = s.size(), m = t.size();
	vector<ll> prev(m + 1, 0);
	vector<ll> cur(m + 1, 0);
	// prev[0] = 1;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j <= m; j++)cur[j] = 0;
		cur[m] += prev[m];
		for (ll j = 0; j < m; j++) {
			if (s[i] == t[j]) {
				cur[j + 1] += prev[j];
			} else cur[j] += prev[j];
		}

		if (s[i] == t[0]) {
			cur[1]++;
		} else cur[0]++;

		for (ll j = 0; j < m; j++)ans += cur[j];
		prev = cur;
		debug(prev);
	} cout << ans << "\n";
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
	// cin >> tt;
	while (tt--)
		solve();
}