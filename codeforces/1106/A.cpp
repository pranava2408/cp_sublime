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
	ll n, c; cin >> n >> c;
	vector<ll> a(n), b(n);
	for (auto &pos : a)cin >> pos;
	for (auto &pos : b)cin >> pos;
	ll ans = 0 ;
	bool ck = false;
	for (int i = 0; i < n; i++) {
		if (a[i] >= b[i]) {
			ans += a[i] - b[i];
		}
		else {
			ck = true;
			break;
		}
	}
	if (!ck) {
		cout << ans << "\n";
		return;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll sum = c;
	for (int i = 0; i < n; i++) {
		if (a[i] >= b[i]) {
			sum += a[i]-b[i];
		}else{
			cout<<-1<<"\n";
			return;
		}
		
	}
	cout<<sum<<"\n";

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