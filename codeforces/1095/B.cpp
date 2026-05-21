#include <bits/stdc++.h>
#include <climits>
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

template <typename T>
struct SparseTable {
	int n;
	int max_log;
	std::vector<std::vector<T>> table;
	std::function<T(T, T)> op;

	// op: The operation to perform (e.g., min, max, gcd)
	SparseTable(const std::vector<T>& a, std::function<T(T, T)> operation) : op(operation) {
		n = a.size();
		max_log = std::floor(std::log2(n)) + 1;
		table.assign(max_log, std::vector<T>(n));

		for (int i = 0; i < n; i++) {
			table[0][i] = a[i];
		}

		for (int j = 1; j < max_log; j++) {
			for (int i = 0; i + (1 << j) <= n; i++) {
				table[j][i] = op(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	// Range query for [L, R] (inclusive)
	T query(int L, int R) {
		int j = std::floor(std::log2(R - L + 1));
		return op(table[j][L], table[j][R - (1 << j) + 1]);
	}
};


void solve() {
	ll n; cin >> n;
	vector<int> a(n);
	for (auto &pos : a)cin >> pos;
	SparseTable<int> st(a, [](int a, int b) { return std::min(a, b); });
	SparseTable<int> st1(a, [](int a, int b) { return std::max(a, b); });
	SparseTable<int> st2(a, [](int a, int b) { return std::gcd(a, b); });
	ll answer = 0;
	for (ll i = 0; i < n; i++) {
		ll low = 0, high = i;
		ll ans = -1;
		while (low <= high) {
			ll mid = (low + high) >> 1;
			ll gc = st2.query(mid, i);
			ll len = st1.query(mid, i) - st.query(mid, i);
			if (len > gc) {
				low = mid + 1;
			} else if (gc > len) {
				high = mid - 1;
			} else {
				ans = mid;
				low = mid + 1;
			}
		}
		low = 0, high = i;
		ll ans1 = 0;
		while (low <= high) {
			ll mid = (low + high) >> 1;
			ll gc = st2.query(mid, i);
			ll len = st1.query(mid, i) - st.query(mid, i);
			if (len > gc) {
				low = mid + 1;
			} else if (gc > len) {
				high = mid - 1;
			} else {
				ans1 = mid;
				high = mid - 1;
			}
		}

		answer += ans - ans1 + 1;
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