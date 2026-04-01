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
  ll n;cin>>n;
  vector<ll> a(n);
  for(auto &pos:a)cin>>pos;
  for(ll i=0;i<n;i++){
  	ll cnt = 0,cnt1=0;
  	for(ll j=i+1;j<n;j++){
  		if(a[j]<a[i])cnt++;
  		else if(a[j]>a[i])cnt1 ++;
  		// ll mini = min(a[i],a[j]);
  		
  	}
  	cout<<max(cnt,cnt1)<<" ";
  }	
  cout<<"\n";
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