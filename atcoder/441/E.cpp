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
	string str; cin >> str;
	map<ll, ll> cnt;
	cnt[0]++;
	vector<ll> prev(3, 0);
	// prev[0] = 1;
	ll sum = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll val = 1;
		if (str[i] == 'B')val = -1;
		else if (str[i] == 'C')val = 0;
		vector<ll> cur(3, 0);



		if (val == 1) {
			cur[2] = prev[2] + 1;
			cur[2] += prev[0];
			cur[0] = cnt[sum + 1];
			cur[1] = prev[1] - cur[0];
		} else if (val == -1) {
			cur[1] = prev[1] + 1;
			cur[1] += prev[0];
			cur[0] = cnt[sum - 1];
			cur[2] = prev[2] - cur[0];
		}
		else {
			debug("this");
			cur = prev;
			// for (ll j = 0; j < 3; j++)cur[j]++;
			cur[0]++;
		}
		sum += val;
		cnt[sum]++;
		prev = cur;
		ans += prev[2];
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