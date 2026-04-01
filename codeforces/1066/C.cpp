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
	ll n , k, q; cin >> n >> k >> q;
	vector<ll> diff(n + 1, 0);
	vector<ll> diff1(n + 1, 0);
	while (q--) {
		ll type; cin >> type;
		ll l, r ; cin >> l >> r;
		l--;
		if (type == 1) {
			diff[l]++;
			diff[r]--;
		} else {
			diff1[l]++;
			diff1[r]--;
		}
	}
	vector<ll> ans(n, -1);
	ll sum = 0 ;
	ll sum1 = 0;
	for (ll i = 0; i < n; i++) {
		sum += diff[i];
		sum1 += diff1[i];
		// debug(sum1)
		if (sum > 0) {
			ans[i] = k ;
			if (sum1 > 0) {
				ans[i] = k + 1;
			}
		}
	}
	ll val = 0;
	sum = 0;
	for (ll i = 0; i < n; i++) {
		sum += diff1[i];
		debug(sum);
		if (sum > 0 && ans[i] == -1) {
			ans[i] = val++;
			if (val == k)val = 0;
		} else if (ans[i] == -1)ans[i] = k + 1 ;
	}
	for (auto pos : ans)cout << pos << " ";
	cout << '\n';

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