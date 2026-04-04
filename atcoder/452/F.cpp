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
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;

	auto get = [&](ll x)->ll{
		ordered_set<ll> temp;
		temp.insert(a[0]);
		ll low = 0;
		ll cur = 0;
		ll ans = 0;
		if (x == 0) {
			ans = 1;
		}
		for (ll i = 1; i < n; i++) {
			cur += (temp.size() - temp.order_of_key(a[i]));
			temp.insert(a[i]);
			if (cur < x) {
				continue;
			}
			while (low <= i && cur >= x) {
				ll ct = temp.order_of_key(a[low]);
				cur -= ct;
				temp.erase(temp.find_by_order(ct));
				low ++;
			}

			ans += low;
			if (low > 0) {
				low --;
				ll ct = temp.order_of_key(a[low]);
				cur += ct;
				temp.insert(a[low]);
			}
		}
		debug(ans);
		return ans ;
	};


	cout << get(k) - get(k + 1) << "\n";
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