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
	for (auto & pos : a)cin >> pos;
	// ll sum = accumulate(a.begin(), a.end(), 0ll);
	// ll maxi = *max_element(a.begin(), a.end());
	// auto ck = [&](ll val)->bool{
	// 	if (val < maxi)return false;

	// 	// multiset<ll> temp(a.begin(), a.end());
	// 	// while (temp.size()) {
	// 	// 	auto it = temp.begin();
	// 	// 	ll need = val - *it;
	// 	// 	temp.erase(it);
	// 	// 	if (need == 0) {
	// 	// 		continue;
	// 	// 	}
	// 	// 	auto itt = temp.lower_bound(need);
	// 	// 	if (itt == temp.end() || *itt != need) {
	// 	// 		return false;
	// 	// 	}

	// 	// 	temp.erase(itt);
	// 	// }
	// 	return true;
	// };
	// set<ll> answer;
	// for (ll i = 1; i * i <= sum; i++) {
	// 	if (sum % i == 0) {
	// 		if (ck(i)) answer.insert(i);
	// 		if (ck(sum / i))answer.insert(sum / i);
	// 	}
	// }

	
	sort(a.begin(), a.end());
	set<ll> ans;
	if (n % 2 == 0) {
		ll cur = a[0] + a[n - 1];
		bool ck = true;
		for (ll i = 0; i < n / 2; i++) {
			if ((a[i] + a[n - i - 1]) == cur) {

			} else ck = false;
		}

		if (ck)ans.insert(cur);
	}



	ll idx = n - 2;
	while (idx >= 0 && a[idx] == a[n - 1])idx--;

	if ((idx + 1) % 2 == 0) {
		bool ck = true;
		for (ll i = 0, j = idx; i < (idx + 1) / 2; i++, j--) {
			if ((a[i] + a[j]) != a[n - 1]) {
				ck = false;
			}
		}

		if (ck)ans.insert(a[n - 1]);
	}
	
	for (auto pos : ans)cout << pos << " ";
	cout << "\n";
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