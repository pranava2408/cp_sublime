#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE
// #include "../../debug.h"
// #else
// #define debug(...)
// #endif

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


	auto query = [&](ll l, ll r)->ll{
		cout << 1 << " " << l << " " << r << endl;
		ll val; cin >> val;
		cout << 2 << " " << l << " " << r << endl;
		ll val1 ; cin >> val1;
		return val1 - val;
	};
	ll len = query(1, n);

	ll answer = -1;
	ll low = 1, high = n;

	while (low <= high) {
		ll mid = (low + high) >> 1;

		ll va = query(1, mid);
		
		if (va > 0) {
			answer = mid ;
			high = mid - 1;
		} else low = mid + 1;
	} cout << "! " << answer << " " << (answer + len - 1) << endl;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
// 	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
// 	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
// #endif
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}