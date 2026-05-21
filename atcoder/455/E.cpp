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
	string str; cin >> str;
	auto get = [&](char A, char B)->ll{
		ll ret = 0;
		map<ll, ll> su;
		su[0] ++;
		ll sum = 0;
		for (ll i = 0; i < n; i++) {
			ll cur = 0;
			if (str[i] == A) {
				cur = 1;
			} else if (str[i] == B) {
				cur = -1;
			}

			sum += cur;
			ret += su[sum];
			su[sum]++;
		}
		debug(ret);
		return ret;
	};

	ll answer = get('A', 'B') + get('A', 'C') + get('B', 'C');
	// cout << answer << endl;

	ll diff1 = 0, diff2 = 0;
	map<pair<ll, ll>, ll> cnt;
	cnt[ {0, 0}]++;
	ll a = 0, b = 0, c = 0;
	ll total = 0 ;
	for (ll i = 0; i < n; i++) {
		if (str[i] == 'A') {
			a++;
			diff1 ++;
		} else if (str[i] == 'B') {
			b++;
			diff1 --;
			diff2--;
		}
		else {
			c++;
			diff2 ++;
		}
		total += cnt[ {a-b, c-b}];
		cnt[ {diff1, diff2}]++;
	}
	// cout << total << endl;
	answer -= 2 * total;
	// cout<<answer<<endl;
	answer = ((n * (n + 1)) / 2) - answer;
	cout << answer << endl;
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