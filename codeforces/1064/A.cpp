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
	set<ll> temp;
	for (ll i = 1; i <= n; i++)temp.insert(i);
	ll idx = n;
	vector<ll> ans(n + 1, -1);
	for (ll i = n - 1; i >= 1; i--) {
		cout << "? 2 " << i << " " << idx << endl;
		ll val ; cin >> val;
		if (val != 0) {
			ans[i] = val;
			temp.erase(val);
		} else {
			idx = i;
		}
	}
	for (ll i = n; i >= 1; i--) {
		if (ans[i] == -1) {
			ans[i] = *temp.begin();
			temp.erase(temp.begin());
		}
	}
	cout << "! ";
	for (ll i = 1; i <= n; i++)cout << ans[i] << " ";
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
	// int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}