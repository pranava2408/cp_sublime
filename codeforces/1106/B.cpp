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
		vector<ll> graph[n + 1];
		for (int i = 2; i <= n; i++) {
			ll par ; cin >> par;
			graph[par].push_back(i);
		}

		vector<ll> dp(n + 1, -1);
		vector<ll> height(n + 1, -1);

		function<ll(ll)> dpval = [&](ll node)->ll{
			if (height[node] != -1)return height[node];
			ll h = 0;
			for (auto &pos : graph[node]) {
				h = max(h, dpval(pos));
			}
			return height[node] = h + 1;
		};

		function<ll(ll)> dpval1 = [&](ll node)->ll{
			if (dp[node] != -1)return dp[node];
			ll ans = 0 ;
			ll maxi = 0;
			ll secondMaxi = 0;
			for (auto &pos : graph[node]) {
				ans += dpval1(pos);
				if (dpval(pos) > maxi) {
					secondMaxi = maxi;
					maxi = dpval(pos);
				} else {
					secondMaxi = max(secondMaxi, dpval(pos));
				}
			}
			ans += secondMaxi + 1;
			return dp[node] = ans;
		};

		cout << dpval1(1) << "\n";
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