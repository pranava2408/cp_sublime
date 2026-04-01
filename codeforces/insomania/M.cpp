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
	ll n, m; cin >> n >> m;
	if (n > m) swap(n, m);
	ll answer = 0;
	for (ll i = 1; i <= n; i++) {
		ll cnt = 0;
		ll idx = 63 - __builtin_clzll(i);
		set<ll> idxs;
		for (ll j = idx; j >= 0; j--) {
			if (i & (1 << j)) {

			}
			else {
				idxs.insert(j);
			}
		}
		ll len = idxs.size();
		auto get = [&](ll val)->ll{
			if (val <= 0)val = 1;
			ll ans = 0;
			for (ll j = 63;j >= 0; j--) {
				if (val & (1LL << j)) {
					// debug("here");
					if (idxs.count(j)) {

					} 
					else break;
				} else if (idxs.count(j)) {
					ll ct = 0 ;
					for (auto pos : idxs) {
						if (pos < j)ct++;
					}
					ans += (1LL << ct);
				}
				if(j==0)ans ++;
			}
			
			// debug(val,ans);
			return ans;
		};
		ll first = get(n - i + 1) - get(m - i + 1);
		
		for(ll j=1;j<10;j++){
			debug(get(j));
		}
		
		answer += first;
		ll second = get(-i) -  get(n - i);

		debug(i, first, second,idxs);
		answer += 2 * second;
	}
	cout << answer << endl;
	// cout << ans << "\n";
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