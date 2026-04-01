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



const int MAXN = 200005;
const int MAXLOG = 19; // K = ceil(log2(MAXN))

long long st[MAXN][MAXLOG + 1]; // Sparse Table
int log_table[MAXN];          // Precomputed logarithms

// Function to compute GCD (for C++14 compatibility or custom implementation)
long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

// Function to build the Sparse Table
void build_sparse_table(const vector<long long>& arr, int n) {
	// Precompute logarithms
	log_table[1] = 0;
	for (int i = 2; i <= n; i++) {
		log_table[i] = log_table[i >> 1] + 1;
	}

	// Initialize the first column with the array elements
	for (int i = 0; i < n; i++) {
		st[i][0] = arr[i];
	}

	// Fill the rest of the table using dynamic programming
	for (int j = 1; j <= MAXLOG; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

// Function to query the GCD of a subarray [L, R] (inclusive, 0-indexed)
long long query_gcd(int L, int R) {
	if (L > R)return 0;
	int j = log_table[R - L + 1];
	return gcd(st[L][j], st[R - (1 << j) + 1][j]);
}



void solve() {


	ll n; cin >> n;
	vector<ll> a(n);
	for(auto &pos:a)cin>>pos;
	build_sparse_table(a, n);
	ll ans = 0;
	for (ll i = 0; i < n - 1; i++) {
		// debug(ans);
		ll right = query_gcd(i + 1, n - 1);
		ll left = query_gcd(0, i);
		if (left == right) {
			ans  ++;
			continue;
		}
		ll idx = -1;
		// ll value = 0;
		ll low = -1, high = i - 1;
		while (low <= high) {
			ll mid = (low + high) >> 1;
			ll val = query_gcd(0, mid);
			if (val % right == 0) {
				idx = mid;
				low = mid + 1;
			} else high = mid - 1;
		}


		ll gc = gcd(right, query_gcd(idx + 2, i));
		if (gc == right) {
			ans ++ ;
			continue;
		}

		idx = -1;
		low = i - 1, high = n - 2;
		while (low <= high) {
			ll mid = (low + high) >> 1;
			ll val = query_gcd(i + 1, mid);
			if (val % left == 0) {
				idx = mid;
				low = mid + 1;
			} else high = mid - 1;
		}


		gc = gcd(left, query_gcd(idx + 2, n - 1));
		if (gc == left) {
			ans ++ ;
			continue;
		}



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