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
	ll n, h, l; cin >> n >> h >> l;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	ll mini = min(l, h);
	ll maxi =  max(h, l);
	ll can = 0;
	ll less = 0;
	for (auto pos : a) {
		can += (pos > mini && pos <= maxi);
		less += (pos <= mini);
	}

	if (mini == maxi) {
		cout << (less >> 1) << "\n";
		return;
	}
	ll ans = min(can, less);
	less -= ans;
	ans += (less >> 1);
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