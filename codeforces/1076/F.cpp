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
	ll n, sx, sy, ex, ey; cin >> n >> sx >> sy >> ex >> ey;
	map<ll, ll> mini, maxi ;
	vector<ll> x(n), y(n);
	for (auto &pos : x)cin >> pos;
	for (auto &pos : y)cin >> pos;
	for (ll i = 0; i < n; i++) {
		if (mini.find(x[i]) == mini.end())mini[x[i]] = y[i];
		// if(maxi.find(x[]))
		mini[x[i]] = min(mini[x[i]], y[i]);
		maxi[x[i]] = max(maxi[x[i]], y[i]);
	}
	ll ans = ey - sx;

	ll len = mini.size();
	vector<pair<ll, ll>> temp;
	for (auto pos : mini)temp.emplace_back(pos.second, maxi[pos.first]);
	ll bottom = max(temp[0].second - sy, 0ll) + max(temp[0].second, sy) - temp[0].first;
	ll top = max(sy - temp[0].first, 0ll) + temp[0].second -  min(sy, temp[0].first);
	vector<ll> prev  = {bottom, top};

	for (ll i = 1; i < len; i++) {
		vector<ll> cur(2, 1e18);
		vector<ll> ys = {temp[i - 1].first, temp[i - 1].second};
		for (ll j = 0; j < 2; j++) {
			ll Sy = ys[j];
			ll bottom = max(temp[i].second - Sy, 0ll) + max(temp[i].second, Sy) - temp[i].first;
			ll top = max(Sy - temp[i].first, 0ll) + temp[i].second -  min(Sy, temp[i].first);
			cur[0] = min(cur[0], bottom + prev[j]);
			cur[1] = min(cur[1], top + prev[j]);
		}
		prev = cur;
	}


	ll answer = ex - sx;

	answer += min(prev[0] + abs(temp.back().first - ey) , prev[1] + abs(temp.back().second - ey) );
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