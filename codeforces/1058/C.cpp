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
	ll n ; cin >> n;
	if (n == 0) {
		// cout << 0 << endl;
		cout<<"YES"<<endl;
		return;
	}
	ll cnt = __builtin_popcountll(n);
	// if (cnt % 2 == 1) {
	// 	cout << "NO" << endl;
	// 	return;
	// }

	ll temp = __builtin_ctzll(n);
	debug(temp);
	ll tot = 64 - __builtin_clzll(n);
	// debug(tot);
	ll left = tot - temp;
	left >>= 1;
	// ll mid =
	ll val = (1LL << tot) - 1 ;
	val ^= ((1LL << (left + temp)) - 1);

	ll answer =  (val & n) + (1LL << temp) - 1ll ;
	debug(val);
	ll other  = (1LL << temp) - 1;
	// debug(other);
	ll ct = 64ll - __builtin_clzll(answer);
	other *= (1LL << ct);
	answer += other;

	// cout << answer << endl;

	auto rev = [&](ll val)->ll{
		if (val == 0)return 0;
		// while (val > 0 && val % 2 == 0)val >>= 1;
		ll tot = __builtin_ctz(val);
		val >>= (tot);
		ll len = 64 - __builtin_clzll(val);
		ll xo = 0;
		for (ll i = 0; i < len; i++) {
			if (val & (1LL << (len - 1 - i ))) {
				xo ^= (1LL << i);
			}
		}
		return xo;
	};
	
	if((answer^rev(answer))==n){
		cout<<"YES"<<endl;
		// cout<<"NO"<<endl;
		return;
	}
	cout<<"NO"<<endl;
	
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