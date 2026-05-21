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
	for (auto &pos : a)cin >> pos;
	vector<ll> height(n + 1);
	height[n] = 1e18;
	height[n - 1] = a[n - 1];
	for (ll i = n - 2; i >= 0; i--) {
		if (height[i + 1] < a[i]) {
			height[i] = a[i] - (a[i] - height[i + 1]);
		}
		else height[i] = a[i];
	}


	vector<ll> suff(n + 1, 0);
	for (ll i = n - 1; i >= 0; i--) {
		suff[i] = a[i] - height[i] + suff[i + 1];
	}
	// debug(height);
	// debug(suff);
	// ll ans = suff[0];

	stack<ll> st;
	vector<ll> idx(n, -1);
	for (ll i = 0; i < n; i++) {
		while (st.size() && height[st.top()] >= height[i]) {
			st.pop();
		}


		if (st.size()) {
			idx[i] = st.top();
		}

		st.push(i);
	}
	ll ans = suff[0];
	debug(ans);
	debug(height);
	debug(idx);
	for (ll i = 0; i < n; i++) {
		if (height[i] != 0) {
			ll id = idx[i];
			ll have = i - id-1;
			ll cur = suff[0] + have;
			if (height[i] < a[i]) {
				cur --;
			}
			// cout << have << endl;
			ans = max(ans, cur);

		}

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
	cin >> tt;
	while (tt--)
		solve();
}