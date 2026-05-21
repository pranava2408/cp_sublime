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
	ll a, n; cin >> a >> n;
	debug(a, n);
	vector<ll> digit(n);
	for (auto &pos : digit)cin >> pos;
	debug(a, digit);
	string cur = to_string(a);
	ll len = cur.size();
	string fir;
	for (ll i = 0; i < len - 1; i++) {
		fir += (char)('0' + digit.back());
		debug(i);
	}
	string sec;
	ll dig = digit[0];
	if (dig == 0 && n != 1) dig = digit[1];
	char fun = (char)('0' + dig);
	sec += fun;
	for (ll i = 0; i < len; i++) {
		debug(i);
		char tem = (char)('0' + digit[0]);
		sec += tem;
	}
	debug(fir, sec);
	ll ans = 1e18;
	if (fir.size())
		ans = min(ans, abs(a - stoll(fir)));
	if (sec.size())
		ans = min(ans, abs(a - stoll(sec)));
	set<ll> tem(digit.begin(), digit.end());
	string total ;
	for (ll i = 0; i < len; i++) {
		debug(i);
		ll looking = cur[i] - '0';
		// bool ck = false;

		// else {
		ll less = digit[0] , more = digit[0];
		for (ll j = 0; j < n; j++) {
			if (digit[j] < looking) {
				less = digit[j];
			} else if (digit[j] > looking) {
				more = digit[j];
				break;
			}
		}

		debug(less, more);
		string tem1 , tem2;
		tem1 = total, tem2 = total;
		char need = (char)('0' + less);
		char need1 = (char) ('0' + more);

		char mini1 = (char)('0' + digit[0]);
		char maxi1 = (char)('0' + digit.back());
		debug(mini1, maxi1);
		tem1 += need;
		tem2 += need1;
		while (tem1.size() != len) tem1 += maxi1;
		while (tem2.size() != len) tem2 += mini1;
		debug(tem1, tem2);
		ans = min(ans, abs(a - stoll(tem1)));

		ans = min(ans, abs(a - stoll(tem2)));
		// 	cout << ans << "\n";
		// 	return;
		// }

		if (tem.count(looking)) {
			total += cur[i];

		} else break; 

		ans = min(ans, abs(a - stoll(total)));


	}
	cout << ans << "\n";
	// ans = min(ans, abs(a - stoll(total)))
	// cout << 0 << "\n";


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