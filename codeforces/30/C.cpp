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
	ll n , m; cin >> n >> m;
	vector<ll> a(n), b(m), c(m);
	for (auto &pos : a)cin >> pos;
	for (auto &pos : b)cin >> pos;
	for (auto &pos : c)cin >> pos;
	multiset<ll> swords(a.begin(), a.end());
	// for(auto pos:a)swords.insert(pos);
	vector<ll> order, other;
	for (ll i = 0; i < m; i++) {
		if (c[i] != 0)order.push_back(i);
		else other.push_back(i);
	}
	sort(order.begin(), order.end(), [&](ll A, ll B) {
		// ll diff1  = c[a] - b[a];
		// ll diff2 = c[B] - b[B];
		if (b[A] < b[B])return true;
		else if (b[A] == b[B]) {
			// if (diff1 > diff2)return true;
			return c[A] > c[B];
		}
		return false;
	});
	ll ans = 0;
	for (auto pos : order) {
		auto it = swords.lower_bound(b[pos]);
		if (it == swords.end())continue;
		ans ++ ;
		ll val = *it;
		swords.erase(it);
		if (c[pos] != 0) {
			val = max(val, c[pos]);
			swords.insert(val);
		}
	} 
	sort(other.begin(),other.end(),[&](ll A,ll B){
		return b[A]<b[B];
	});
	// debug(order);
	debug(order);debug(other);
	for(auto pos:other){
		auto it = swords.lower_bound(b[pos]);
		if(it==swords.end())continue;
		ans ++;
		swords.erase(it);
	}cout<<ans<<endl;
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