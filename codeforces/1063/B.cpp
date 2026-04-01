#include <bits/stdc++.h>
#include <climits>
#include <ostream>
#include <type_traits>

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
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	string str; cin >> str;
	// ll l = 0;
	// vector<ll> prefix(n + 1, 0);
	// for (ll i = 0; i < n; i++) {
	// 	prefix[i + 1] = prefix[i] + a[i];
	// }

	// // string ans;
	// // for (ll i = 0; i < n; i++)ans += '0';
	// vector<ll> diff(n + 1, 0);
	// map<ll, ll> mini, maxi;

	// for (ll i = 0; i < n; i++) {
	// 	ll val = i + a[i];
	// 	if (mini.find(val) == mini.end()) {
	// 		mini[val] = i;
	// 	}


	// 	maxi[a[i] - i] = i;
	// }

	// for (ll i = 0; i < n; i++) {
	// 	ll looking = i + a[i];

	// 	if (mini.find(looking) != mini.end()) {
	// 		ll idx = mini[looking];
	// 		if (idx < i) {
	// 			ll len = i - idx + 1;
	// 			ll sum = (len * (2 * a[i] + (len - 1))) >> 1;
	// 			ll presu = prefix[i + 1] - prefix[i];
	// 			if (presu == sum) {
	// 				diff[idx] ++;
	// 				diff[i + 1] --;
	// 			}
	// 		}

	// 	}

	// 	looking = a[i] - i;

	// 	if (maxi.find(looking) != mini.end()) {
	// 		ll idx = maxi[looking];
	// 		if (idx > i) {
	// 			ll len =  idx - i + 1;
	// 			ll sum = (len * (2 * a[i] + (len - 1))) >> 1;
	// 			ll presu = prefix[idx + 1] - prefix[i];
	// 			if (presu == sum) {
	// 				diff[i] ++;
	// 				diff[idx + 1] --;
	// 			}
	// 		}

	// 	}

	// }

	// vector<pair<ll, ll>> ans;
	// ll sum = 0;
	// for (ll i = 0; i < n; i++) {
	// 	sum += diff[i];
	// 	if (sum > 0) {
	// 		if (ans.size() > 0) {
	// 			if (i == ans.back().second + 1) {
	// 				ans.back().second = i;
	// 			}
	// 		} else ans.push_back({i, i});
	// 	}else if(str[i]=='1'){
	// 		cout<<-1<<endl;
	// 		return;
	// 	}
	// }
	// debug(ans);


	// vector<pair<ll, ll>> tot;
	// for (auto pos : ans) {
	// 	bool ck = false;
	// 	for (ll j = pos.first; j <= pos.second; j++) {
	// 		if (str[j] == '1') {
	// 			ck = true;
	// 			break;
	// 		}
	// 	} if (ck) {tot.push_back(pos);}
	// }
	// if(tot.size()<=5){
	// 	cout<<tot.size()<<endl;
	// 	for(auto pos:tot){
	// 		cout<<pos.first + 1<<' '<<pos.second+1<<endl;
	// 	}return;
	// }cout<<-1<<endl;
	
	
	// ll maxi = LLONG_MIN;
	
	
	vector<pair<ll, ll>> get;
	
	
	
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