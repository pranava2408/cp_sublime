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
	ll n , m; cin >> n >> m;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	ll sum = accumulate(a.begin(), a.end(), 0ll);
	if (sum < m) {
		cout << 1 << endl;
		return;
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(100001, 0));
	dp[n][0] = 1;
	for (ll i = n - 1; i >= 0; i--) {
		if (a[i] <= 100000 && i == n - 1)
			dp[i][a[i]] = 1;
		for (ll j = i + 2; j <= n; j++) {
			for (ll sum = 0; sum <= 100000; sum ++) {
				ll tot = (a[i] + sum) % m;
				if (tot > 100000)continue;
				dp[i][tot] += dp[j][sum];
			}
		}
	}
	// debug(dp);
	vector<ll> suf(n, 0);
	suff[n - 1] = (a[n - 1] > 100000);
	
	map<pair<ll, ll>, ll> cnt;

	function<ll(ll, ll)> dpval = [&](ll idx , ll need)->ll{
		// debug(idx, need);
		if (idx >= n)return 0;
		if (cnt.find({idx, need}) != cnt.end())return cnt[{idx, need}];
		if (need <= 100000)return dp[idx][need];
		ll sum = a[idx];
		ll answer = 0;
		if (sum == need)answer ++;
		ll looking = need + m - sum;
		looking %= m;
		// answer += dpval(idx + 2, looking);
		for (ll j = idx + 2; j < n; j++)answer += dpval(j, looking);
		return cnt[{idx, need}] = answer;
	};
	ll answer  = 1;

	for (ll i = 0; i < n; i++)answer += dpval(i, 0);
	cout << answer << endl;
	// debug(dpval(6, 2));
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