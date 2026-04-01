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
	multiset<ll> a[2];
	for (ll i = 0; i < n; i++) {
		ll val; cin >> val;
		a[0].insert(val);
	}
	for (ll i = 0; i < m; i++) {
		ll val; cin >> val;
		a[1].insert(val);
	}
	// debug(n,m);
	// cout<<n<<" "<<m<<endl;
	ll turn = 0;
	while (1) {
		ll val = *--a[turn].end();
		auto it = --a[!turn].end();
		// if (it == a[!turn].end())it--;
		ll va = *it;
		a[!turn].erase(it);
		if (va > val)
			a[!turn].insert(va - val);

		if (a[!turn].size() == 0) {
			cout << (turn ? "Bob" : "Alice") << '\n';
			return;
		}
		turn ^= 1;
	}
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