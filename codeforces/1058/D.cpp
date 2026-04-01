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
	auto query = [&](vector<ll> &A) {
		cout << "? " << A.size() << " ";
		for (auto pos : A)cout << pos << " ";
		cout << endl;
		ll val; cin >> val;
		return val;
	};

	vector<ll> answer(2 * n + 1, -1);

	ll l = 1, r = 2;
	vector<ll> idxs;
	vector<ll> other;
	idxs.push_back(1);
	ll lim = n << 1;
	// idxs.push_back()
	// ll idx =
	
	while (r <= lim) {
		idxs.push_back(r);
		ll val = query(idxs);

		if (val != 0) {
			answer[r] = val;
			other.push_back(r);
			idxs.pop_back();
		}
		r++;
	}
	for(auto pos:idxs){
		other.push_back(pos);
		answer[pos]=query(other);
		other.pop_back();
	}
	

	cout << "! ";
	for (ll i = 1; i <= 2 * n; i++) {
		cout << answer[i] << " ";
	} cout << endl; cout << flush;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
// 	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
// 	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
// #endif
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}