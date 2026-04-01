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
	vector<ll> Arr(n), Brr(n);
	for (auto &pos : Arr)cin >> pos;
	for (auto &pos : Brr)cin >> pos;


	// vector<ll> idxs ;

	for (ll j = 20; j >= 0; j--) {

		vector<ll> a, b;
		for (ll k = 0; k < n; k++) {
			a.push_back(((1LL << j)&Arr[k]) != 0);
			b.push_back(((1LL << j)&Brr[k]) != 0);
		}


		ll idx  = -1;
		for (ll i = 0; i < n; i++)if (a[i] != b[i])idx = i;
		ll A = accumulate(a.begin(), a.end(), 0ll) % 2;
		ll B = accumulate(b.begin(), b.end(), 0ll) % 2;

		if (idx == -1) {
			if (A && B) {
				// cout << "Tie\n";
				// return;
				continue;
			}
			if (!A && !B) {
				continue;
				// cout << "Tie\n";
				// return;
			}


			cout << (A ? "Ajisai\n" : "Mai\n");
			return;
		}

		ll sum = (A + B) % 2;

		if (sum == 0) {
			continue;
		}

		if (idx % 2 == 0) {
			cout << "Ajisai\n"; return;
		} cout << "Mai\n"; return;


	}
	cout << "Tie\n";


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