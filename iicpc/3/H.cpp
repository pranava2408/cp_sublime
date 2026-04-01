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
	ll sum = accumulate(a.begin(), a.end(), 0ll);
	ll low = 0;
	ll answer = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] != 0) {
			answer = i;
			// low = i + 1;
		}
	}

	if (sum == 1) {
		if (answer == 0)answer++;
		cout << answer << endl;
		return;
	}
	ll high = 1e18;
	auto ck = [&](ll mid)->bool{
		__int128 need = 0;
		ll other = 0;
		if (mid >= n) {
			ll len = mid - n;
			if (len >= 64) {
				return false;
			}
			need = (1LL << len);

		} else{
			other += a[mid];
			need = 1;
		}
		ll Mid = min(mid - 1 , n - 1);
		for (ll i = Mid + 1 ; i < n; i++)other += a[i];
		for (ll i = Mid; i >= 1; i--) {
			debug((ll)need);
			if (a[i] <= need) {

				need += (need - a[i]);

				if (need > sum)return false;

			} else {
				other += (a[i] - need);
			}

		}
		debug((ll)need, a[0], other);
		bool check = (a[0] + other) >= need;
		// a[0] -= other;
		return check;
	};
	debug(ck(6));
	while (low <= high) {
		ll mid = (low + high) >> 1;
		if (ck(mid)) {
			debug(mid);
			answer = mid;
			low = mid + 1;
		} else high = mid - 1;
	} cout << answer << endl;
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