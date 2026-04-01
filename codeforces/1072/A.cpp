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
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;


	vector<ll> diff;
	for (ll i = 1; i < n; i++)diff.push_back(abs(a[i] - a[i - 1]));
	debug(n, a, diff);
	stack<ll> idxs;
	vector<ll> ans(n, 0);
	vector<ll> left(n - 1, 0);
	auto right = left;
	for (ll i = 0; i < n - 1; i++) {
		while (idxs.size() && diff[idxs.top()] >= diff[i])idxs.pop();
		left[i] = i;
		if (idxs.size())left[i] =  i - idxs.top() - 1;
		// ans[diff[i]] += ()
		idxs.push(i);
	}
	// debug(ans);
	while (idxs.size())idxs.pop();
	for (ll i = n - 2; i >= 0; i--) {
		while (idxs.size() && diff[idxs.top()] >= diff[i])idxs.pop();
		right[i] = n - 2 - i;
		if (idxs.size())right[i] = idxs.top() - i - 1;

		// ans[diff[i]] += (right[i] + 1) * (left[i] + 1);
		idxs.push(i);

	}

	vector<ll> prev(n, -1);
	vector<ll> pre(n, -1);

	for (ll i = 0; i < n - 1; i++) {


		ans[diff[i]] += (right[i] + 1) * (left[i] + 1);
		if (prev[diff[i]] == (i - left[i])) {
			ans[diff[i]] -= (left[pre[diff[i]]] + 1) * (right[i] + 1);
		}

		prev[diff[i]] = i - left[i];
		pre[diff[i]] = i;
	}

	debug(left, right);
	debug(ans);
	for (ll i = n - 2; i >= 0; i--)ans[i] += ans[i + 1];
	// for(auto pos:ans)cout<<pos<<" ";
	for (ll i = 1; i < n; i++)cout << ans[i] << " ";
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
	cin >> tt;
	while (tt--)
		solve();
}