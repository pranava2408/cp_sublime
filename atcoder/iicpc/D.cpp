#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

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
	vector<ll> doors[n];
	vector<pair<ll, ll>> lim(n);
	for (ll i = 0; i < n; i++) {
		ll val ; cin >> val;
		ll x, y; cin >> x >> y;
		lim[i] = {x, y};
		vector<ll> a(val);
		for (auto &pos : a)cin >> pos;
		doors[i] = a;
	}


	vector<ll> have(n, 0);
	vector<ll> points;
	map<ll, vector<ll>> start;
	for (ll i = 0; i < n; i++) {
		ll val = lim[i].first;

		points.push_back(val);
		start[val].push_back(i);
		ll sum = 0;
		for (auto pos : doors[i]) {
			points.push_back(points.back() + pos);
			start[points.back()].push_back(i);
			sum += pos;
		}
		have[i] = lim[i].second - lim[i].first - sum;
	}
	set<ll> Points(points.begin(), points.end());
	multiset<ll> just;
	vector<ll> prev(n, -1);
	ll ans = 0;
	for (auto pos : Points) {
		for (auto posi : start[pos]) {
			if (prev[posi] != -1) {
				just.erase(just.lower_bound(prev[posi]));
			}
			prev[posi] = pos + have[posi];
			just.insert(prev[posi]);
		}
		if (just.size() == n) {
			ans = max(ans, *just.begin() - pos);
		}

	} cout << ans << '\n';

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