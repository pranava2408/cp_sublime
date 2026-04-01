#include <algorithm>
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
	vector<vector<ll>> mat(n, vector<ll>(2));
	for (ll j = 0; j < 2; j++) {
		for (ll i = 0; i < n; i++) {
			cin >> mat[i][j];
		}

	}
	debug(mat);
	ll mini1 = mat[n - 1][1];
	ll maxi1 = mini1;
	vector<ll>pref(n + 1, LLONG_MAX), maxi(n + 1, LLONG_MIN);
	for (ll i = 0; i < n; i++) {
		pref[i + 1] = min(pref[i], mat[i][0]);
		maxi[i + 1] = max(maxi[i], mat[i][0]);
	}
	vector<ll>fuck(2 * n + 1, LLONG_MAX);
	for (ll i = n - 1; i >= 0; i--) {
		maxi1 = max(maxi1, mat[i][1]);
		mini1 = min(mini1, mat[i][1]);
		ll maxi2 = max(maxi1, maxi[i + 1]), mini2 = min(mini1, pref[i + 1]);
		// cout<<mini2<<" "<<maxi2<<endl;
		debug(mini2, maxi2, mini1, maxi1);
		fuck[mini2] = min(fuck[mini2], maxi2);
	}
	debug(fuck);
	ll fuck_mini = LLONG_MAX;
	ll ans = 0;
	for (ll i = 2 * n; i >= 1; i--) {
		fuck_mini = min(fuck_mini, fuck[i]);


		if (fuck_mini != LLONG_MAX) {
			ans += (2 * n - fuck_mini + 1);
		}


	} cout << ans << endl;
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