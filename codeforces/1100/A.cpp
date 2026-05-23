#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

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
	// ll sum = accumulate(a.begin(), a.end() , 0ll);
	// ll avg = (sum / n);

	// ll ans = 0;
	// for(auto pos:a){
	// 	ans = max(ans,abs(pos-avg));
	// }
	// ll ans1 = 0;
	// avg ++;
	// for(auto pos:a){
	// 	ans1 = max(ans1,abs(pos-avg));
	// }
	// cout<<min(ans,ans1)<<"\n";

	// ll maxi = *max_element(a.begin(),a.end());
	ll answer = 1e18;
	for (ll avg = 1; avg <= 1000; avg++) {
		ll ans = 0;
		for (auto pos : a) {
			ans = max(ans, abs(pos - avg));
		}
		
		answer = min(answer,ans);
	}
	cout<<answer<<"\n";

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