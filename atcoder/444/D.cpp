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
	sort(a.begin(), a.end());
	ll carry = 0;

	ll dig = 1;

	ll idx = 0;
	string ans;
	while (true) {
		while (idx < n && a[idx] < dig)idx++;
		ll cnt = n - idx;
		carry += cnt;
		if (idx == n) {
			while (carry > 0) {
				ans += (char)('0' + carry % 10);
				carry /= 10;
			}
			break;
		}
		ans += (char)('0' + carry % 10);
		carry /= 10;
		dig ++;
	}
	
	reverse(ans.begin(), ans.end());
	for (auto pos : ans)cout << pos;
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