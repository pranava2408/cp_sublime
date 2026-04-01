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
	ll h, w, n; cin >> h >> w >> n;
	vector<pair<ll, ll>> pieces;
	multiset<pair<ll, ll>> height, width;
	for (ll i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		pieces.push_back({a, b});
		height.insert({a, i});
		width.insert({b, i});
	}
	ll x = 1, y = 1;
	vector<pair<ll, ll>> ans(n);
	while (height.size() != 0) {
		pair<ll, ll> H = *--height.end();
		auto W = *--width.end();
		ll points;
		if (H.first == h) {
			points = H.second;
			ans[points] = {x, y};
			// height.erase(height.lower_bound({pieces[points].first, points}));
			// width.erase(width.lower_bound({pieces[points].second, points}));
			y += pieces[points].second;
			w -= pieces[points].second;;
		} else {
			points = W.second;
			ans[points] = {x, y};
			// height.erase(height.lower_bound({pieces[points].first, points}));
			// width.erase(width.lower_bound({pieces[points].second, points}));
			x += pieces[points].first;
			h -= pieces[points].first;
		}


		height.erase(height.lower_bound({pieces[points].first, points}));
		width.erase(width.lower_bound({pieces[points].second, points}));
	}


	for (auto pos : ans) {
		cout << pos.first << " " << pos.second << "\n";
	}
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