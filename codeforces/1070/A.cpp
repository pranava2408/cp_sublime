#include <bits/stdc++.h>
#include <queue>

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
	debug(n);
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll ans = 0;
	debug(a,n);
	for (ll i = n - 1; i >= 0; i--) {
		// if(pq.size()){
		// 	ll val = pq.top();
		// }
		
		while (pq.size()) {
			ll val = pq.top();
			if (a[i] > val) {
				pq.pop();
				ans++;
			}
			else break;
		}
		pq.push(a[i]);
	}
	cout<<ans<<'\n';
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
	// debug(tt);
	while (tt--)
		solve();
}