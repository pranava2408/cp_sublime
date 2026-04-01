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

vector<ll> divisors[200002];
ll have[200002];


void solve() {
	ll n; cin >> n;
	vector<ll> a(n), b(n);
	for (auto &pos : a)cin >> pos;
	for (auto &pos : b)cin >> pos;
	debug(a);
	debug(b);
	// debug(have, 200002);
	// for (ll i = 0; i < 200002; i++) {
	// 	if (have[i]) {
	// 		debug(i);
	// 	}
	// }
	for (ll i = 0; i < n; i++) {
		for (auto pos : divisors[a[i]])have[pos] ++;
	}

	for (ll i = 0; i < n; i++) {
		for (auto pos : divisors[a[i]])have[pos] --;
		for (auto pos : divisors[a[i]]) {
			if (have[pos] && pos > 1) {
				for (auto posi : a) {
					for (auto F : divisors[posi])have[F] = 0;
				}
				cout << 0 << endl;
				return;
			}
		}
		// have[a[i]] ++ ;
		for (auto pos : divisors[a[i]])have[pos] ++;

	}



	for (ll i = 0; i < n; i++) {
		for (auto pos : divisors[a[i]])have[pos] --;
		ll val = a[i] + 1;
		for (auto pos : divisors[val]) {
			if (have[pos] && pos > 1) {
				for (auto posi : a) {
					for (auto F : divisors[posi])have[F] = 0;
				}
				cout << 1 << endl;
				return;
			}
		}
		for (auto pos : divisors[a[i]])have[pos] ++;
	}
	cout << 2 << endl;

	for (auto posi : a) {
		for (auto F : divisors[posi])have[F] = 0;
	}

	return;

}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif
	for (ll i = 1; i <= 200001; i++) {
		for (ll j = i; j <= 200001; j += i) {
			divisors[j].push_back(i);
		}
	}

	for (ll i = 0; i <= 200001; i++)have[i] = 0;
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}