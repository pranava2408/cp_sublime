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


	ll bit = n - 1;






	ll val = (1LL << n) - 1;

	set<ll> left;
	for (ll i = 0; i < (1LL << n); i++) {
		left.insert(i);
	}

	ll msb = n - 1;
	ll cur = n;
	vector<ll> ans;
	ll tot = 1LL << n;
	while (ans.size() < tot) {
		ll have = 1LL << (n - cur) ;
		have -= ans.size();

		debug(have);
		if (have == 0) {
			cur --;
			val ^= (1LL << msb);
			msb--;
		} else {
			for (ll i = 0; i < have; i++) {
				ans.push_back((i << (msb + 2)) + val);
			}
		}
	}

	for (auto pos : ans) {
		cout << pos << " ";
	} cout << '\n';
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