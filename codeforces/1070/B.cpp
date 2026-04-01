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
	string str; cin >> str;
	auto ck = [&](ll mid)->bool{
		vector<ll> diff(n + 1, 0);

		for (ll i = 0; i < n; i++) {
			if (str[i] == '1') {
				ll idx = i , last = i + mid + 1;
				diff[i]++;
				if (last > n) {
					diff[n] --;
					diff[0] ++;
					diff[last - n]--;
				}
				else {
					diff[last] --;
				}
			}
		}
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			sum += diff[i];
			if (sum <= 0)return false;
		} return true;
	};
	ll answer = n ;
	ll low = 0, high = n - 1;
	while (low <= high) {
		ll mid = (low + high) >> 1;
		if (ck(mid))
		{
			answer = mid;
			high = mid - 1;
		} else low = mid + 1;
	}
	cout << answer << "\n";
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