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
	// vector<pair<ll, ll>> points(n);
	vector<vector<ll>> map(n + 1);
	vector<ll> have(n + 1, 0);
	for (ll i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		have[y] = 1;
		map[x].push_back(y);
	}
	// for (ll i = 0; i < n; i++)have[points[i].second] = 1;
	for (ll i = 1; i <= n; i++)have[i] += have[i - 1];
	vector<ll> cnt1(n + 1, 0);
	ll l1 = 1e18 , r1 = 0;
	ll l2 = 1e18, r2 = 0;
	auto add1 = [&](ll val)-> void{
		cnt1[val]++;
		l1 = min(l1, val);
		r1 = max(r1, val);
	};
	auto add2 = [&](ll val)-> void{
		l2 = min(l2, val);
		r2 = max(r2, val);
	};
	auto remove1 = [&](ll val)->void{
		cnt1[val]--;

		while (cnt1[l1] == 0 && l1 <= n) {
			l1 ++;
		}

		while (cnt1[r1] == 0 && r1 >= 1) {
			r1--;
		}
	};
	for (ll i = 1; i <= n; i++) {
		for (auto pos : map[i])
			add1(pos);
	}
	debug(map);

	debug(l1, r1, l2, r2);
	// sort(points.begin(), points.end());
	// debug(points);
	ll ptr = 0;
	ll answer  = 0;
	for (ll ptr = 1; ptr <= n; ptr++) {
		ll ct = map[ptr].size();
		if (ct == 0)continue;
		for (auto pos : map[ptr]) {
			remove1(pos);
			add2(pos);
		}
		
		ll l = max(l1, l2);
		ll r = min(r1 , r2);


		if (r > l)
			answer += have[r] - have[l - 1] - 1;

		// ptr ++ ;
	}
	cout << answer << "\n";

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