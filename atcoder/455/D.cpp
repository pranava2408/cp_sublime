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
	ll n, q; cin >> n >> q;
	vector<ll> parent(n + 1, -1);
	vector<ll> child(n + 1, -1);
	vector<ll> base(n + 1, -1);
	for (ll i = 1; i <= n; i++) {
		base[i] = i;
	}
	vector<ll> isbase = base;

	while (q--) {
		ll x, y; cin >> x >> y;
		if (isbase[x] != -1) {
			base[isbase[x]] = -1;
			isbase[x] = -1;
		}
		else {
			child[parent[x]] = -1;
		}
		child[y] = x;
		parent[x] = y;
	}

	for (ll i = 1; i <= n; i++) {
		ll cnt = 0;
		ll node = base[i];
		while (node != -1) {
			debug(node);
			cnt ++;
			node = child[node];
		}
		cout << cnt << " ";

	}
	cout << endl;
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