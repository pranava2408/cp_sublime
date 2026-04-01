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
	vector<ll> v(n), w(n), s(n);
	for (auto &pos : v)cin >> pos;
	for (auto &pos : w)cin >> pos;
	for (auto &pos : s)cin >> pos;
	ll ans = accumulate(v.begin(), v.end(), 0ll);
	// ll rem = 0;
	vector<pair<ll, ll>> just;
	for (ll i = 0; i < n; i++) {
		just.emplace_back(w[i], s[i]);
	}
	sort(just.begin(), just.end());
	map<ll, ll> ct ;
	vector<ll> done(n, false);
	ll cnt = 0;
	// for (ll i = 0; i < n; i++) {
	// 	if (ct[just[i].second] == 0) {
	// 		ct[just[i].second] = 1;
	// 		done[i] = true;
	// 		cnt ++;
	// 	}
	// }
	// cout << ans << endl;
	for (ll i = 0; i < n; i++) {
		just[i].first *= ct[just[i].second];
		ct[just[i].second] ++;
		// if (!done[i]) {
		// ans += just[i].first * cnt * ct[just[i].second];
		// cnt ++;
	}

	sort(just.begin(), just.end());
	for (ll i = 0; i < n; i++) {
		ans += i * just[i].first;	
	}


	cout << ans << "\n";

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