#include <bits/stdc++.h>
#include <pthread.h>

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

vector<ll> sums[1000000];

void output(ll i) {
	cout << i;
	if (i <= 9)return;

	ll val = i;
	ll su = 0;
	while (val != 0) {
		ll dig = val % 10;
		su += dig;
		val /= 10;
	}

	output(su);
}

void solve() {
	string str; cin >> str;
	ll n = str.size();
	debug(str);
	vector<ll> cnt(10, 0);
	ll sum = 0;
	for (auto pos : str) {
		sum += (pos - '0');
		cnt[pos - '0']++;
	}
	if (n == 1) {
		cout << str << "\n";
		return;
	}
	debug(sum);

	for (ll i = 1; i <= sum; i++) {
		ll temp = sum;
		ll left = n;
		bool ck = true;
		for (ll j = 0; j < 10; j++) {
			if (cnt[j] < sums[i][j]) {
				ck = false;
			} else {
				left -= (sums[i][j]);
				temp -= sums[i][j] * j;
			}
		}



		if (ck && temp == i && left > 1) {
			for (ll j = 9; j >= 0; j--) {
				ll ct = cnt[j] - sums[i][j];
				for (ll k = 0; k < ct; k++) {cout << j;}
			}

			output(i);
			cout << "\n";
			return;
		}
	}

}





int main() {


	// sums[0] = temp;
	for (ll i = 1; i < 10; i++) {
		vector<ll> temp(10, 0);
		temp[i] = 1;
		sums[i] = temp;
	}
	for (ll i = 10; i < 1000000; i++) {
		vector<ll> temp(10, 0);
		ll su = 0;
		ll val = i;
		while (val != 0) {
			ll dig = val % 10;
			su += dig;
			temp[dig] ++;
			val /= 10;
		}
		for (ll j = 0; j < 10; j++)temp[j] += sums[su][j];
		sums[i] = temp;
	}
	// debug(sums[900000]);
	// debug(output(99999));
	// output(99999);
	// for

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