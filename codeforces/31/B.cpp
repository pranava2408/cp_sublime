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
	// string ans;
	// for(ll i=0;i<n;i++){
	// 	string temp;cin>>temp;
	// 	if(temp<ans)ans = temp + ans;
	// 	else ans += temp;
	// }	cout<<ans<<"\n";

	vector<string> a(n);
	for (auto &pos : a)cin >> pos;
	string ans;
	for (ll i = 0; i < n; i++) {
		// string temp; cin >> temp;
		auto temp = a[i];
		// if (temp < ans)ans = temp + ans;
		// else ans += temp;
		ans = min(ans+temp, temp + ans);
	}	cout << ans << "\n";
	// vector<ll> suff(n);
	// suff[n - 1] = n - 1;
	// for (ll i = n - 2; i >= 0; i--) {
	// 	suff[i] = suff[i + 1];
	// 	if (a[suff[i]] >= a[i])suff[i] = i;
	// }
	// ll idx = 0 ;
	// // string ans;
	// ans.clear();
	// while (idx < n) {
	// 	ans = a[suff[idx]] + ans;
	// 	for (ll i = idx; i < suff[idx]; i++) ans += a[i];
	// 	idx = suff[idx] + 1;
	// } cout << ans << endl;
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