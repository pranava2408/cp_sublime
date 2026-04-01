#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

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
	ll n , m , c;
	cin >> n >> m >> c;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;

	sort(a.begin(), a.end());
	set<ll> st(a.begin(), a.end());
	st.insert(m);

	// vector<ll> prefix(n + 1);
	// for (ll i = 0; i < n; i++)prefix[i + 1] = prefix[i] + a[i];
	ll sum = 0;

	ll prev = 0;

	for (auto i : st) {

		if (i == 0) {
			continue;
		}

		ll have = i - prev;

		auto val = [&](ll mid)->ll{
			ll nex = i + mid;

			ll ans = 0;

			if (nex >= m) {
				ll left = nex - m ;
				ans += (upper_bound(a.begin(), a.end(), left) - a.begin());
				nex = m - 1;
			}

			ans += (upper_bound(a.begin(), a.end(), nex) - lower_bound(a.begin(), a.end(), i));
			return ans;
		};

		ll low = 0;
		ll high = m - 1;
		ll answer = 0;
		while (low <= high) {
			ll mid = (low + high) >> 1;
			ll va = val(mid);
			if (va >= c) {
				answer = va;
				high = mid - 1;
			} else low = mid + 1;
		}
		sum += answer * have;
		prev = i;
	} cout << sum << "\n";

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