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
	ll n, k, p, m; cin >> n >> k >> p >> m;
	vector<pair<ll, ll>> arr(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first;
	}
	arr[p - 1].second = 1;
	ll ans = 0;
	while (m) {
		ll idx = -1;
		for (ll i = 0; i < k; i++) {
			if (arr[i].second) {
				idx = i;
				break;
			}
		}

		// cout << idx << endl;

		if (idx != -1) {
			pair<ll, ll> cur = arr[idx];
			if (arr[idx].first > m)break;
			arr.erase(arr.begin() + idx);
			arr.push_back(cur);
			m -= cur.first;
			ans ++;
			continue;
		}

		idx = k - 1;
		for (ll i = k - 2; i >= 0; i--) {
			if (arr[i].first < arr[idx].first) {
				idx = i;
			}
		}
		// cout << idx << endl;
		auto cur = arr[idx];
		if (arr[idx].first > m)break;
		arr.erase(arr.begin() + idx);
		arr.push_back(cur);
		m -= cur.first;
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