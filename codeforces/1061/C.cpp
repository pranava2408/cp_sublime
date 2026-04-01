#include <bits/stdc++.h>
#include <ios>

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


vector<ll> divisors[200001];

void solve() {
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	// auto ck =[&](ll mid)->bool{
	// 	ll cnt =0 ;
	// 	ll looking = mid<<2 ;
	// 	// looking ++;
	// 	for(ll i=0;i<n;i++){
	// 		if(a[i]%mid==0 || a[i]>=looking){}
	// 		else cnt ++;
	// 	}return cnt<=k;
	// };
	// ll ans = 0;
	// ll low = 1,high = 1e18;
	// while(low<=high){
	// 	ll mid = (low+high)>>1;
	// 	if(ck(mid)){
	// 		ans = mid;
	// 		low = mid+1;
	// 	}else high = mid -1 ;
	// }cout<<ans<<'\n';
	vector<ll> have(n + 1, 0), diff(n + 2, 0);
	for (ll i = 0; i < n; i++) {
		ll looking = a[i] / 4;
		debug(looking);
		diff[0] ++;
		diff[looking + 1]--;

		for (auto pos : divisors[a[i]]) {
			if (pos > looking)have[pos]++;
		}
	}
	// debug(a);
	debug(diff);
	debug(have);
	ll tot =diff[0];
	ll answer  = 1;
	
	for(ll i=1;i<=n;i++){
		tot += diff[i];
		tot += have[i];
		debug(i,tot);
		ll left = n - tot;
		if(left<=k)answer = i;
		tot -=have[i];
	}cout<<answer<<endl;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("F:\\cp_sublime\\input.txt", "r", stdin);
	freopen("F:\\cp_sublime\\output.txt", "w", stdout);
	freopen("F:\\cp_sublime\\debug.txt", "w", stderr);
#endif
	for(ll i=1;i<=200000;i++){
		for(ll j=i;j<=200000;j+=i)divisors[j].push_back(i);
	}
	int tt = 1;
	cin >> tt;
	while (tt--)
		solve();
}