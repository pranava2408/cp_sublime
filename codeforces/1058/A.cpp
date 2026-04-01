#include <bits/stdc++.h>
#include <climits>

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
	map<ll, ll> cnt;
	for (ll i = 0; i < n; i++) {
		ll val; cin >> val;
		cnt[val]++;
	}
	ll maxi = 0;
	// for(auto &pos:cnt)maxi = max(maxi,pos.second);
	// ll answer = 0;
	// while(cnt[answer]==maxi)answer ++ ;
	// cout<<answer<<endl;
	// if(cnt[0]==n){
	// 	cout<<1<<endl;
	// 	return;
	// }cout<<0<<endl;
	// ll answer = 0;
	// ll mini = LLONG_MAX;
	ll mex = 0;
	while (cnt[mex]) mex++;
	cout<<mex<<endl;

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