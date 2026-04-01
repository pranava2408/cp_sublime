#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;


void solve() {
	ll n; cin >> n;
	string str; cin >> str;
	ll answer = 1e18;
	vector<ll> a(n, -1);
	for (ll i = 0; i < n; i++)if (str[i] == 'a')a[i] = 1;
	map<ll,set<ll>> suff;
	suff[0].insert(n);
	ll sum =0 ;
	for(ll i=n-1;i>=0;i--){
		sum += a[i];
		suff[sum].insert(i);
	}
	if(sum == 0){
		cout<<0<<endl;
		return;
	}
	sum = 0;
	for(ll i=0;i<n;i++){
		ll looking = -sum;
		sum += a[i];
		auto it = suff[looking].lower_bound(i);
		if(it==suff[looking].end())continue;
		// cerr<<*it<<" "<<i<<endl;
		answer = min(answer, *it - i);
	}cout<<(answer==n?-1:answer)<<endl;
	
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