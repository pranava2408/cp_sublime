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
	vector<ll> a(2 * n);
	for (ll i = 0; i < 2 * n; i++)cin >> a[i];
	// stack<ll> st;
	// // vector<ll> cnt(n + 1, 0);
	// map<ll, ll> temp;
	// ll mex = 0;
	// ll cur = 0;
	// for (ll i = 0; i < 2*n; i++) {
	// 	debug(st);
	// 	if (st.size() && st.top() == a[i]) {
	// 		temp[a[i]]++;
	// 		st.pop();
	// 	} else {
	// 		temp.clear();
	// 		cur = 0 ;
	// 		st.push(a[i]);
	// 	}

	// 	while (temp[cur]) {cur ++;}
	// 	mex = max(mex,cur);
	// }
	// cout<<mex<<endl;

	ll idx = -1, idx1 = -1;
	for (ll i = 0; i < 2 * n; i++) {
		if (a[i] == 0) {
			if (idx == -1) {
				idx = i;
			} else {idx1 = i;}
			// break;
		}
	}



	ll ans = 1;
	map<ll, ll> cnt;
	for (ll i = idx; i <= idx1; i++) {
		ll diff = i - idx;
		ll prev = idx1 - diff;
		if (a[prev] != a[i]) {
			cnt.clear();
			break;
		}
		cnt[a[i]]++;
	}
	debug(idx, idx1);


	for (ll i = 1; i <= idx; i++) {
		ll oth = idx1 + i;
		if (oth >= 2 * n || a[oth] != a[idx - i])break;
		cnt[a[oth]]++;
	}


	ll mex = 0;
	while (cnt[mex])mex++;
	ans = max(ans, mex);

	cnt.clear();

	cnt[0]++;

	for (ll i = 1; i <= idx; i++) {
		ll oth = idx + i;
		if (oth >= 2 * n || a[oth] != a[idx - i])break;
		cnt[a[oth]]++;
	}
	
	
	mex = 0;
	while (cnt[mex])mex++;
	ans = max(ans, mex);
	
	cnt.clear();
	
	
	cnt[0]++;

	for (ll i = 1; i <= idx1; i++) {
		ll oth = idx1 + i;
		if (oth >= 2 * n || a[oth] != a[idx1 - i])break;
		cnt[a[oth]]++;
	}
	
	
		
	mex = 0;
	while (cnt[mex])mex++;
	ans = max(ans, mex);
	
	
	cout<<ans<<endl;
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