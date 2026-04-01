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
	ll n, c1, c2 ; cin >> n >> c1 >> c2;
	c1 = min(c1, c2);

	ll answer = 0;
	// for (ll i = 0; i < n; i++) {
	while (n--) {
		string str ; cin >> str;
		// ll cnt1 = count(str.begin(), str.end(), 'M');
		// vector<ll> ct(26, 0);
		map<char, ll>ct;
		// set<char> temp;
		for (ll i = 0; i < 3; i++)ct[str[i]]++;
		ll nex = 3 * c1 ;
		for (auto pos : ct) {
			if (pos.second >= 2) {
				nex = min(nex , c1 + c2);
			}
		} answer += nex;
	}
	cout << answer << endl;
	// }
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