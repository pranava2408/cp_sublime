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
	ll n, k, d; cin >> n >> k >> d;
	vector<string> temp;
	for (ll i = 0; i < n; i++) {
		string cur; cin >> cur;
		temp.push_back(cur);
	}



	ll low = 1;
	ll high = 300000;
	ll ans = 0;


	auto ck = [&](ll mid)->bool{
		map<string, ll> cnt;
		vector<string> then;
		ll ct = 0;
		for (ll i = 0; i < n; i++) {
			if (i > d) {
				ll prev = i - d - 1;
				cnt[then[prev]]--;
			}
			string sub;
			if (temp[i].size() < mid) {
				sub = temp[i];
				// continue;
			}
			else {
				sub = string(temp[i].begin() , temp[i].begin() + mid);
				ct += cnt[sub];
			}

			cnt[sub]++;

			then.push_back(sub);
		}

		return ct >= k;

	};

	while (low <= high) {
		ll mid = (low + high) >> 1;
		if (ck(mid)) {
			ans = mid ;
			low = mid + 1;
		} else high = mid  - 1 ;
	}

	cout << ans << endl;


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