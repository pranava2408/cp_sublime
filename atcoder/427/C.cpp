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
	ll n , m ; cin >> n >> m;
	vector<ll> graph[n];
	ll answer = m;
	for (ll i = 0; i < m; i++) {
		ll u , v ; cin >> u >> v;
		u-- , v-- ;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	for (ll i = 0; i < (1ll << n); i++) {
		vector<bool> have(n, false);
		// vector<ll> have;
		for (ll j = 0; j < n; j++) {
			if (i & (1LL << j)) {
				have[j] = true;
				// have.emplace_back(j);
			}
		}
		ll cur = m;
		for (ll J = 0; J < n; J++) {
			if (have[J]) {
				for (auto pos : graph[J]) {
					if (!have[pos]) {
						cur --;
					}
				}
			}
		}
		debug(have);
		debug(cur);
		answer =min(answer,cur);
	}
	cout<<answer<<endl;
	
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