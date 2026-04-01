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
	ll n , m; cin >> n >> m;
	vector<pair<ll, ll>> jus(m);
	for (auto &pos : jus)cin >> pos.first >> pos.second;
	// debug(jus);
	vector<ll> ans(n + 1, -1);
	// for (ll i = 0; i < n; i++)ans[i + 1] = i + 1;
	ll tot = n + 1;
	vector<ll> cnt(n + 2, 0);
	for (ll i = 0; i < m; i++) {
		cnt[jus[i].first] ++;
		cnt[jus[i].second + 1] --;
	}
	ll val = 0;
	for (ll i = 1; i <= n; i++) {
		val += cnt[i];
		if (val == m) {
			debug(0);
			// for (ll j = 1; j <= n; j++)ans[j] = -1;
			ans[i] = 0;
			ll l = 1;
			for (ll j = 1; j <= n; j++) {
				if (ans[j] == -1) {
					ans[j] = l++;
				}
			} for (ll j = 1; j <= n; j++) {
				cout << ans[j] << " ";
			} cout << endl; return;
		}

	}


	for (ll j = 1; j <= n - 1; j++) {
		bool ck1 = false, ck = false;
		for (ll i = 0; i < m; i++) {
			if (jus[i].first <= j && jus[i].second == j) {
				ck1 = true;
			}
			if (jus[i].first == j+1) {
				ck = true;
			}
		}
		if (ck && ck1)continue;
		debug(1);
		if (!ck1) {
			ans[j] = 0;
			ans[j + 1] = 1;
		} else {
			ans[j] = 1;
			ans[j + 1] = 0;
		}
		ll l = 2;
		for (ll i = 1; i <= n; i++) {
			if (ans[i] == -1)ans[i] = l++;
		}
		for (ll i = 1; i <= n; i++) {
			cout << ans[i] << " \n"[i == n];
		} return;

	}
	debug(2);

	ans[1] = 0;
	ans[n] = 1;
	for (ll i = 2; i < n; i++) {ans[i] = i;}
	for (ll i = 1; i <= n; i++)cout << ans[i] << " \n"[i == n];

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