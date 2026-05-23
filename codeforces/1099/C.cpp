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
	map<ll, ll> prev;
	prev[a[0]] = 0;
	ll op = 0;
	while (1) {
		op ++;
		if (a[0] & 1) {
			a[0]++;
		} else {
			a[0] >>= 1;
		}
		if (prev.find(a[0]) != prev.end())break;
		prev[a[0]] = op;
	}
	debug(prev);
	for (ll i = 1; i < n; i++) {
		map<ll, ll> cur;

		if (prev.find(a[i]) != prev.end()) {
			cur[a[i]] = prev[a[i]];
		}



		ll ops = 0;
		while (1) {
			ops ++;
			if (a[i] & 1) {
				a[i]++;
			} else {
				a[i] >>= 1;
			}
			if(cur.find(a[i])!=cur.end())break;
			if (prev.find(a[i]) != prev.end()) {
				cur[a[i]] = ops;
				cur[a[i]] += prev[a[i]];
			}
		}
		prev = cur;
		debug(cur);


	}

	ll ans = 1e18;
	for (auto &pos : prev)ans = min(ans, pos.second);
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