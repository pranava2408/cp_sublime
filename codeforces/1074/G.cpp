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

ll cnt[1000005] = {0};
ll sum[1000005] = {0};

void solve() {
	ll n; cin >> n;
	vector<ll> mexs, nexmex;
	vector<vector<ll>> mat;
	for (ll i = 0; i < n; i++) {
		ll len; cin >> len;
		vector<ll> a(len);
		for (auto &pos : a)cin >> pos;
		for (auto pos : a)cnt[pos]++;
		ll mex = 0;
		while (cnt[mex])mex++;
		mexs.emplace_back(mex);
		mex ++;
		while (cnt[mex])mex++;
		nexmex.emplace_back(mex);
		for (auto pos : a)cnt[pos] = 0;
		mat.emplace_back(a);
	}
	ll su = 0;
	for (ll i = 0; i < n; i++) {
		su += mexs[i];
		sum[mexs[i]] += nexmex[i];
	}
	for (ll i = 0; i < n; i++)cnt[mexs[i]]++;
	debug(su);
	debug(mat);
	debug(mexs);
	debug(nexmex);
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		map<ll, ll> ct;
		for (auto pos : mat[i])ct[pos]++;
		for (auto pos : mat[i]) {
			ll cur = (su - mexs[i]);
			if (pos < mexs[i] && ct[pos] == 1) {
				cur += pos;
			} else {
				cur += mexs[i];
			}
			cur *= (n - 1);
			cur -= pos * cnt[pos];
			cur += sum[pos];
			ans += cur;
			debug(pos, cur);

		}
	}
	cout << ans << "\n";
	for (auto pos : mexs)sum[pos] = 0, cnt[pos] = 0;

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