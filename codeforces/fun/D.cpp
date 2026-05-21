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
	ll val = m;
	bool check = true;

	for (ll i = 2; i * i <= val; i++) {
		if (val % i == 0) {
			check = false;
			break;
		}
	}


	if (check && m>1) {
		cout << val << "\n";
		return;
	}

	if (__gcd(n, m) != 1) {
		cout << -1 << "\n";
		return;
	}

	while (1) {
		bool ck = true;
		for (ll i = 2; i * i <= val; i++) {
			if (val % i == 0) {
				ck = false;
				break;
			}
		}
		if (ck && val > 1) {
			cout << val << '\n';
			return;
		}
		val += n;
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