#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;


void solve() {
	ll n, y; cin >> n >> y;
	vector<ll>a(n);
	for (auto &pos : a)cin >> pos;
	ll answer = 0;
	for (ll i = 0; i < n; i++)answer ^= a[i];
	ll ans = 0;
	ll maxi = answer;
	for(ll i=1;i<(1LL<<y);i++){
		// cerr<<i<<endl;
		if(n%2==1){
			// cerr<<i<<endl;
			if((answer^i) > maxi){
				maxi = (answer^i);
				ans = i;
			}
		}
	}
	// cerr<<answer<<" "<<ans<<endl;
	// cerr<<maxi<<endl;
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
	// cin >> tt;
	while (tt--)
		solve();
}