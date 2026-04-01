#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

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


template<typename F>
ll binary_search(ll low , ll high , F ck) {
	ll answer = -1;
	while (low <= high) {
		ll mid = (low + high) >> 1;
		if (ck(mid)) {
			answer = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return answer;
}

template<typename F>
ld binary_search_real(ld l, ld r, F ck, int iter = 100) {
	for (ll i = 0; i < iter; i++) {
		ld x = (l + r) / 2;
		(ck(x) ? l : r) = x;
	}
	return (l + r) / 2;
}

template<typename F>
ld ternary_search(ld l, ld r, F f) {
	ld ep = 1e-12;
	while (r - l > ep) {
		ld m1 = l + (r - l) / 3;
		ld m2 = r - (r - l) / 3;
		ld f1 = f(m1);
		ld f2 = f(m2);
		if (f1 < f2)
			l = m1;
		else
			r = m2;
	}
	return l;
}

template<typename F>
ll ternary_search_integers(ll l, ll r, F f) {
	ll lo = l - 1, hi = r;
	while (hi - lo > 1) {
		ll mid = (hi + lo) >> 1;
		if (f(mid) > f(mid + 1))
			hi = mid;
		else
			lo = mid;
	} return lo + 1 ;
}

/*
since as we can see the problem has submittions and the submission 
are running too fast probably the run time is very fast
first of all lets try to find the solution for the even case and then we will work 
to the oddd case 
even:
	sort and apply 2 pointer .... try to find case where it fails
odd : prefix and suffix sum will solve right
*/
void solve() {
	ll n , l, r ; cin >> n >> l >> r;
	vector<ll> a(n);
	for (auto &pos : a)cin >> pos;
	sort(a.begin(), a.end());
	vector<ll> prefix(n+1,0);
	for(ll i=0;i<n;i++){
		prefix[i+1] = prefix[i] + a[i];
	}
	ll tot = prefix[n];
	
	ll ans =tot - prefix[((n+1)/2)] - prefix[n/2];
	debug(a);
	for(ll i=0;i<n;i++){
		ll curtot = tot  - a[i];
		ll left = i;
		ll looking = (n-1)/2;
		if(looking==0)continue;
		if(left>=looking){
			ans = max(ans,curtot - prefix[looking] - prefix[looking]);
		}else{
			ans = max(ans,-curtot +2*(prefix[n]-prefix[n-looking]));
		}
	}cout<<ans<<'\n';
	
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