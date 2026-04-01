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

	vector<ll> points;
	vector<ll> prev;

	points.push_back(lim[0].first);
	ll le = doors[0].size();
	for (ll j = 0; j < le; j++) {
		points.push_back(points.back() + doors[0][j]);
	}

	prev.resize(le + 1, 0);
	ll su = accumulate(doors[0].begin(), doors[0].end(), 0ll);

	for (ll i = 0; i <= le; i++) {
		ll last = lim[0].second - su;
		prev[i] = max(prev[i], last - points[i]);
		if (i != le)
			su -= doors[0][i];
	}

	// for (auto pos : prev) {
	// 	cout << pos << " ";
	// } cout << endl;
	// for (auto pos : points) {
	// 	cout << pos << " ";
	// } cout << endl;

	// vector<ll> dp[n];
	// vector<ll> pu[n];
	vector<vector<ll>> dp(n), pu(n);
	dp[0]  = prev;
	pu[0] = points;

	for (ll i = 1; i < n; i++) {


		vector<ll> curpoints;

		curpoints.push_back(lim[i].first);
		ll len = doors[i].size();
		for (ll j = 0; j < len; j++) {
			curpoints.push_back(curpoints.back() + doors[i][j]);
		}
		ll sum = accumulate(doors[i].begin(), doors[i].end(), 0LL);

		vector<ll> cur(len + 1, 0);

		for (ll j = 0; j <= len; j++) {
			ll val = lim[i].second - sum;
			// nex = min(nex, val);
			// cout << val << " " << nex << "#" << curpoints[j] << endl;
			cur[j] = max(cur[j], val - curpoints[j]);
			if (j != len)
				sum -= doors[i][j];
		}

		// debug(prev);
		// debug(points);


		prev = cur;
		points = curpoints;
		dp[i] = prev;
		pu[i] = points;
	}
	// cout << *max_element(prev.begin(), prev.end()) << "\n";


	auto pref = dp;

	debug(pref, pu);



	for (ll i = n - 2; i >= 0; i--) {
		ll sum = accumulate(doors[i].begin(), doors[i].end(), 0ll);
		ll fu = pu[i].size();
		for (ll j = 0; j < fu; j++) {
			ll idx = upper_bound(pu[i + 1].begin(), pu[i + 1].end(), pu[i][j]) - pu[i + 1].begin();
			idx--;
			ll val = 0;
			if (idx >= 0) {
				ll nex = dp[i + 1][idx] + pu[i + 1][idx];
				ll va = lim[i].second - sum;
				nex = min(nex, va);

				val = nex - pu[i][j];

			}


			if (j != fu - 1) {
				sum -= doors[i][j];
			}
			val = max(val, 0ll);
			dp[i][j] = min(dp[i][j], val);

		}
	}

	for (ll i = 1; i < n; i++) {
		ll sum = accumulate(doors[i].begin(), doors[i].end(), 0ll);
		ll fu = pu[i].size();
		for (ll j = 0; j < fu; j++) {
			ll idx = upper_bound(pu[i - 1].begin(), pu[i - 1].end(), pu[i][j]) - pu[i - 1].begin();
			idx--;
			ll val = 0;
			if (idx >= 0) {
				ll nex = pref[i - 1][idx] + pu[i - 1][idx];
				ll va = lim[i].second - sum;
				nex = min(nex, va);

				val = nex - pu[i][j];

			}


			if (j != fu - 1) {
				sum -= doors[i][j];
			}
			val = max(val, 0ll);
			pref[i][j] = min(pref[i][j], val);

		}
	}

	debug(dp, pref);

	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll len = dp[i].size();
		// ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
		for (ll j = 0; j < len; j++)ans = max(ans, min(pref[i][j], dp[i][j]));

		// for (auto pos : dp[i])cout << pos << " ";
		// cout << endl;
	}
	cout << ans << endl;
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