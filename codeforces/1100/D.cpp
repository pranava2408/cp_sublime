#include <algorithm>
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
	ll n; cin >> n;
	vector<ll> a(n), b(n);
	for (auto &pos : a)cin >> pos;
	for (auto &pos : b)cin >> pos;
	ll ans = 0;
	ll low = 1;
	ll high = 2 * n;
	auto ck = [&](ll mid) -> bool{
		ll cnt = 0;
		ll prev = 0;
		vector<ll> temp;
		for (ll i = 0; i < n; i++) {
			ll ct = (a[i] >= mid) + (b[i] >= mid);
			debug(ct);
			if (temp.size() && temp.back() == 0 && ct == 0) {
				continue;
			}
			if (ct==1) {
				continue;
			}
			temp.push_back(ct);
		}
		// reverse(temp.begin(),temp.end());
		debug(temp);
		ll len = temp.size();
		if(len==0){
			return false;
		}

		if (temp[len - 1] == 2) {
			cnt = 1;
		} else {
			// prev = (a[n - 1] >= mid) + (b[n - 1] >= mid);
			prev = temp[len - 1];
		}
		debug(cnt, prev);
		for (ll i = len - 2; i >= 0; i--) {
			ll ct= temp[i];
			if (ct == 2) {
				if (cnt > 0) {
					cnt += 1;
				} else if (prev) {
					cnt = 1;
				} else {
					prev = 1;
				}
			} else if (ct == 1) {
				if (cnt) {

				} else if (prev) {

				} else {
					prev = 0;
				}
			} else {
				if (cnt >= 2) {
					cnt --;
				} else if (cnt == 1) {
					cnt = 0;
					prev = 1;
				}
				else {
					prev = 0;
				}
			}
			debug(cnt, prev);
		}
		return cnt > 0;
	};
	while (low <= high) {
		ll mid = (low + high) >> 1;
		if (ck(mid)) {
			ans = mid ;
			low = mid + 1;
		} else high = mid - 1;
	}

	// cout << ck(8) << endl;
	cout << ans << '\n';
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