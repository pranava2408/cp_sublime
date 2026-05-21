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
	vector<ll> a(n);
	for (auto & pos : a)cin >> pos;
	// set<ll> st;
	// for (ll i = 0; i < n; i++)st.insert(a[i]);
	// ll ans = 1;

	// for (auto pos : st) {
	// 	ll diff = 0;
	// 	ll eq = 0;
	// 	ll greater = 0 ;
	// 	ll less = 0;
	// 	for (ll i = 0; i < n; i++) {
	// 		if (a[i] == pos) {
	// 			diff++;
	// 			eq ++;
	// 		}
	// 		else if (a[i] > pos) {
	// 			diff ++;
	// 			greater ++;
	// 		}
	// 		else {
	// 			less ++;
	// 		}

	// 	}
	// }
	vector<ll> b = a;
	sort(b.begin(), b.end());
	ll med = b[n / 2];

	vector<ll> dp(n + 1, -1e18);
	dp[0] = 0;
	for (ll i = 1; i <= n; i++) {
		ll less = 0 , greater = 0, equal = 0;
		for (ll j = i; j >= 1; j--) {
			ll val = a[j - 1];
			if (val < med) {
				less ++;
			}
			else if (val == med) {
				equal ++;
			} else greater ++;
			ll len = i - j + 1;
			if (len & 1) {
				if (greater + equal > less) {
					ll half = len / 2;
					if (greater <= half) {
						dp[i] = max(dp[i], 1 + dp[j - 1]);
					}
				}
			}
		}


	}
	cout << dp[n] << "\n";
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