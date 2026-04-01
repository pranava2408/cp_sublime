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
		vector<string> mat(n);
		for (auto &pos : mat)cin >> pos;
		vector<ll> prev(n + 1, 0);
		vector<ll> cur(n + 1, 1e18);
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++)cur[j] = 1e18;
			ll cnt = count(mat[i].begin(), mat[i].end(), '#');
			ll white = 0;
			for (ll j = n - 1; j >= 0; j--) {
				cur[j + 1] = prev[j + 1] + cnt + white;
				if (j != n - 1)cur[j + 1] = min(cur[j + 2], cur[j + 1]);
				if (mat[i][j] == '.') {
					white ++;
				} else cnt --;

				debug(white, cnt);
			}

			cur[0] = prev[0] + white + cnt;

			cur[0] = min(cur[0], cur[1]);

			prev = cur;
			debug(prev);
		}

		cout << prev[0] << "\n";


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