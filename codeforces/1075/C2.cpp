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

	// vector<ll> ans(n);
	// ans[n - 1] = 1;
	// set<ll>left;
	// for (ll i = 1; i < n; i++)left.insert(i + 1);
	// for (ll i = 0; i < n - 1; i++) {
	// 	ans[i] = 1 ^ (i + 1);
	// 	left.erase(ans[i]);
	// }
	// ans[0] = *left.begin();
	// for (auto pos : ans)cout << pos << " ";
	// cout << "\n";
	for (ll i = 1; i <= n; i++) {
		ll maxi 
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
	cin >> tt;
	while (tt--)
		solve();
}