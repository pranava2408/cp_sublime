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
	string s, t; cin >> s >> t;
	vector<bool> S(26, false), T(26, false);
	for (ll i = 0; i < n; i++)S[s[i] - 'a'] = true;
	for (ll i = 0; i < m; i++)T[t[i] - 'a'] = true;
	ll q; cin >> q;
	while (q--) {
		string temp; cin >> temp;
		ll len = temp.size();
		bool _1 = true, _2 = true;
		for (ll i = 0; i < len; i++) {
			if (!S[temp[i] - 'a'])_1 = false;
			if (!T[temp[i] - 'a'])_2 = false;
		}


		if (_1 && !_2) {
			cout << "Takahashi\n";
		} else if (_2 && !_1) {
			cout << "Aoki\n";
		} else {
			cout << "Unknown\n";
		}
	}
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