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

ll have[300001] = {0};
vector<ll> divisors[300001];
void solve() {
	ll n; cin >> n;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	for (auto pos : a)have[pos] = 1;
	vector<ll> dp(n + 1, 1e18);
	for (ll i = 1; i <= n; i++) {
		for (auto pos : divisors[i]) {
			ll left = i / pos;
			if (have[pos]) {
				dp[i] = min(1 + (left != 1 ? dp[left] : 0), dp[i]);
			}
		}
	}


	for (ll i = 1; i <= n; i++)cout << (dp[i] == 1e18 ? -1 : dp[i]) << " ";
	cout << "\n";
	for (auto pos : a)have[pos] = 0;
}




int main() {
	for (ll i = 1; i <= 300000; i++)for (ll j = i; j <= 300000; j += i)divisors[j].push_back(i);
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