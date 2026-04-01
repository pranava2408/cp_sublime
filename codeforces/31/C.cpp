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
	ll n , k; cin >> n >> k;
	debug(n,k);
	vector<ll> ans(k, 0);
	for (ll i = 35; i >= 0; i--) {
		if(n&(1LL<<i)){
			
		}else {
			continue;
		}
		debug(i);
		sort(ans.begin(), ans.end());

		// if (n & (1LL << i)) {
		ll can = 0;

		for (ll j = 0; j < k; j++) {
			if ((ans[j] ^ (1LL << i)) > n)break;
			can ++;
		}
		debug(can);
		if (can % 2 == 0) {
				can--;
		}
		// else if (n & (1LL << i)) {
		// 	can--;
		// }

		for (ll j = 0; j < k; j++) {
			if (can > 0) {can--, ans[j] ^= (1LL << i);}
		}

	}
	
	
	// for (auto pos : ans) {
	// 	cout << pos << " ";
	// } cout << "\n";
	debug(ans);
	for (ll i = 35; i >= 0; i--) {
		if(n&(1LL<<i)){
			continue;
		}
		
		debug(i);
		sort(ans.begin(), ans.end());

		// if (n & (1LL << i)) {
		ll can = 0;

		for (ll j = 0; j < k; j++) {
			if ((ans[j] ^ (1LL << i)) > n)break;
			can ++;
		}
		debug(can);
		if (can % 2 == 0) {
			if (n & (1LL << i))
				can--;
		}
		else  {
			can--;
		}

		for (ll j = 0; j < k; j++) {
			if (can > 0) {can--, ans[j] ^= (1LL << i);}
		}

	}
	
	
	// else {

	// }
	for (auto pos : ans) {
		cout << pos << " ";
	} cout << "\n";
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