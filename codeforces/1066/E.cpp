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
	string s, t; cin >> s >> t;
	debug(s, t);
	ll n = t.size();
	vector<ll> cnt(26, 0);
	auto need = cnt;
	for (auto pos : s)need[pos - 'a']++;
	for (auto pos : t)cnt[pos - 'a']++;
	debug(need, cnt);
	ll looking = 0;
	string ans;
	while (ans.size() < n) {

		// debug(ans);
		ll val = s[looking] - 'a';
		for (ll i = 0; i < 26; i++) {
			if (cnt[i] > need[i]) {
				if (i == val) {
					looking ++;
					need[i]--;
				}
				ans += (char)('a' + i);
				cnt[i] --;
				// continue;
				break;
			} else if (cnt[i] > 0 && cnt[i] == need[i]) {
				if (val == i) {
					looking ++;
					need[i]--;
					ans += (char)('a' + i);
					cnt[i] --;
					// continue;
					break;
				}
			}
			if(i==25){
				cout<<"Impossible\n";
				return;
			}
		}
	}
	// cout<<"reached"<<endl;
	cout << (looking != s.size() ? "Impossible" : ans) << endl;
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