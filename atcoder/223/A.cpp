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


void solve() {
	ll n,m;cin>>n>>m;
	vector<pair<ll, ll>> temp;
	for(ll i=0;i<n;i++){
		ll a,b;cin>>a>>b;
		temp.emplace_back(a,b);
	}	
	// we don't take the last element ?
	ll answer = 0;
	vector<ll> pref(n+1,0);
	for(ll i=0;i<n-1;i++){
		pref[i+1] = pref[i] + temp[i].second;
		// answer += temp[i].second;
	}
	answer = pref[n];
	
	// we take the last element ..
	
	
	ll cur = 0;
	ll tot = 0;
	for(ll i=n-1;i>=0;i--){
		if(m>=temp[i].first){
			answer = max(answer,pref[i] + tot);
			m -= temp[i].first;
			tot += temp[i].second;
		}
	}
	answer = max(answer,tot);
	cout<<answer<<"\n";
	
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