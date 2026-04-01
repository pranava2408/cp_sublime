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
	ll n, q; cin >> n >> q;
	ll ans = 0 ;
	vector<pair<ll, ll>> temp;
	for(ll i=0;i<q;i++){
		ll a, b;cin>>a>>b;
		temp.emplace_back(a,b);
	}
	ll l = n,r = 1;
	auto ck = [&](ll m)->bool{
		ll low = r + 1, high = n;
		ll R = r;
		while (low <= high) {
			ll mid = (low + high) >> 1;
			cout << "? " << 1 << " " << mid << endl;
			ll val; cin >> val;
			if (val >= m) {
				R = mid;
				high = mid - 1;
			} else low = mid + 1;
		}
		low  = 1 , high = l-1;
		ll L = l;
		while (low <= high) {
			ll mid = (low + high) >> 1;
			cout << "? " << mid << " " << R << endl;
			ll val; cin >> val;
			if (val >= m) {
				L = mid;
				low = mid + 1;
			} else high = mid - 1;
		}
		for(auto pos:temp){
			if(pos.first<=L && pos.second >=R){
				l = L , r = R;
				return true;
			}
		}return false;
		
		
	};
	ll low = 1, high = n;
	while (low <= high) {
		ll mid  = (low + high) >> 1;
		// cout<<mid<<endl;
		if (ck(mid)) {
			ans = mid ;
			low = mid + 1;
		} else high = mid - 1;
	}cout<<"! "<<ans<<endl;
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