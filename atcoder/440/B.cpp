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
	ll n , m; cin >> n >> m;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	vector<ll> prefix(n + 1, 0);
	for (ll i = 0; i < n; i++)prefix[i + 1] = prefix[i] + a[i];
	debug(prefix);
	ll ans = 1e18;
	for (ll i = 0; i < (m << 1); i++) {
		ll Cur = 0;
		ll j = 1;

		if (j + i >= m) {
			j = (m << 1) - i;
			if(j==0){
				j = 1;
			}
			
		}
		
		
		
		

		while (j <= n) {
			ll cur = (j + i) % (m << 1);

			ll can = m - cur;
			ll sum = prefix[min(n, j + can-1)] - prefix[j-1];
			Cur += sum;

			j += can;
			j += m;
			
			debug(can);
			debug(sum);

		}
		
		// cout<<cur;
		
		// cout<<"\n";
		
		
		ans = min(ans,Cur);



	}
	cout<<ans<<"\n";
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