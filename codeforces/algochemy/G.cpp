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
	vector<ll> a(n);
	for (auto & pos : a)cin >> pos;
	vector<ll> b(m);
	for (auto &pos : b)cin >> pos;
	sort(a.begin(), a.end());
	auto ck = [&](ll mid)->bool{
		priority_queue<ll> vals;
		priority_queue<ll, vector<ll>, greater<ll>> vals1;
		for (ll i = 0; i < m; i++) {
			vals.push(b[i]);
		}

		while (true) {
			debug(vals1);
			ll tp = vals.top();

			if (vals1.size() == n && vals1.top() >= tp)break;

			vals1.push(tp);

			vals.pop();
			vals.push(tp - mid);

			if (vals1.size() > n)vals1.pop();
		}

		debug(vals1.size());

		for (ll i = 0; i < n; i++) {
			if (a[i] > vals1.top())return false;
			vals1.pop();
		}
		return true;
	};
	ll low = 0, high = 1e10;
	ll ans = -1;
	while (low <= high) {
		ll mid = (low + high) >> 1;
		if (ck(mid)) {
			ans = mid ;
			low = mid + 1;
		} else high = mid - 1;
	}


	if (ans == 1e10) {
		cout << "Infinity\n";
		return;
	}
	cout << ans << "\n";
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