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

ll pref[1001][50001];

void solve() {
	ll n , m; cin >> n >> m;
	vector<ll> p(n), v(n);
	for (ll i = 0; i < n; i++)cin >> p[i] >> v[i];
	for (ll i = 0; i <= n; i++)for (ll j = 0; j <= m; j++)pref[i][j] = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= 50000; j++) {
			pref[i][j] = pref[i - 1][j];
			if (j != 0)pref[i][j] = max(pref[i][j], pref[i][j - 1]);
			ll left = j - p[i - 1];
			if (left >= 0)pref[i][j] = max(pref[i][j], v[i - 1] + pref[i - 1][left]);
		}
	}
	ll ans = pref[n][m];
	// cout<<ans<<endl;
	vector<ll> prev(50001, 0);
	vector<ll> cur;
	vector<char> an(n, 'C');
	for (ll i = n - 1; i >= 0; i--) {
		ll left = m - p[i];
		for (ll j = 0; j <= left; j++) {
			ll maxi = pref[i][j] + prev[left - j]+v[i];
			if (maxi == ans) {
				an[i] = 'A';
				break;
			}
		}
		if (an[i] == 'A') {
			for (ll j = 0; j <= m; j++) {
				ll maxi = pref[i][j] + prev[m - j];
				if (maxi == ans) {
					an[i] = 'B';
					break;
				}
			}
		}
		cur = prev;
		for (ll j = p[i]; j <= 50000; j++) {
			cur[j] = max(cur[j], v[i] + prev[j - p[i]]);
		}
		for (ll j = 1; j <= 50000; j++)cur[j] = max(cur[j], prev[j - 1]);
		prev = cur;
	}
	for (auto pos : an)cout << pos;
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
	// cin >> tt;
	while (tt--)
		solve();
}