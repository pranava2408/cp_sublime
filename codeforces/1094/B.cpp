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
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	ll odd = 0, even = 0;
	for (ll i = 0; i < m; i++) {
		ll idx; cin >> idx;
		if (idx & 1) {
			even ++;
		}
		else odd ++;
	}


	vector<pair<ll, ll>> temp;
	for (ll i = 0; i < n; i++) {
		temp.push_back({a[i], i});
	}

	sort(temp.rbegin(), temp.rend());
	ll maxi = 0;
	ll o = 0, e = 0;
	for (ll j = 0; j < n; j++) {
		if (temp[j].first < 0) {
			if (o && temp[j].second % 2) {
				continue;
			}

			if (e && temp[j].second % 2 == 0) {
				continue;
			}

		}
		if (temp[j].second % 2 == 1 && odd) {
			o++;
			maxi += temp[j].first;
			odd --;
		}
		else if (temp[j].second % 2 == 0 && even) {
			e++;
			maxi += temp[j].first;
			even --;
		}
	}

	ll ans = accumulate(a.begin(), a.end(), 0ll) - maxi;
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