#include <bits/stdc++.h>
#include <climits>

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
	ll idx = -1, idx1 = -1;
	for (ll i = 0; i < n; i++) {
		if (a[i] == 1)idx = i;
		if (a[i] == n)idx1 = i;
	}

	vector<pair<ll, ll>> ans;
	if (idx1 > idx) {


		cout << "Yes\n";


		for (ll j = 0; j < idx1; j++)ans.emplace_back(a[j], n);
		for (ll j = idx1 + 1; j < n; j++)ans.emplace_back(1, a[j]);

		for (auto pos : ans) {cout << pos.first << " " << pos.second << '\n';}
		return;
	}


	for (ll i = 0; i < idx1; i++)ans.emplace_back(a[i], n);
	for (ll j = idx + 1; j < n; j++)ans.emplace_back(1, a[j]);

	ll mini = LLONG_MAX;


	for (ll i = 0; i < idx1; i++) {
		mini = min(mini, a[i]);
	}

	ll maxi = LLONG_MIN;
	for (ll j = idx + 1; j < n; j++) maxi = max(maxi, a[j]);

	ll ma = LLONG_MAX;
	bool ck = false;
	ll id =  -1;
	ll val = -1;
	ll Maxi = maxi;
	for (ll i = idx1 + 1; i < idx; i++) {
		if (a[i] < maxi) {
			if (id == -1) {
				id = i - 1;
				val = a[i];
			}
			ck = true;
		}
		if (!ck) {
			// ma = min(ma, a[i]);
		}
		else {

			if (a[i] > val) {
				ans.emplace_back(a[i], val);
			} else ans.emplace_back(a[i], Maxi);

			maxi = max(maxi, a[i]);
		}
	}
	if (id == -1) id = idx - 1;
	if (mini > maxi) {
		cout << "No\n"; return;
	}
	ans.emplace_back(mini, maxi);
	for (ll j = idx1 + 1; j <= id; j++) {
		if (a[j] < maxi) {
			ans.emplace_back(a[j], maxi);
		}
		else if (mini < a[j])ans.emplace_back(mini, a[j]);
		else {
			cout << "No\n";
			return;
		}
	} cout << "Yes\n"; for (auto pos : ans) {cout << pos.first << " " << pos.second << '\n';}
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