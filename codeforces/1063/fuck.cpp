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


vector<ll> divisors[100001];

void solve() {
	ll maxi = 0;
	ll val = 1;
	for (ll i = 1; i <= 100000; i++) {
		ll sum = 0;
		for (auto pos : divisors[i])sum += divisors[pos].size();
		if (sum > maxi) {
			maxi = sum;
			val = i;
		}
	} cout << maxi << " " << val << endl;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif
	for (ll i = 1; i <= 100000; i++) {
		for (ll j = i; j <= 100000; j += i) {
			divisors[j].push_back(i);
		}
	}
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}