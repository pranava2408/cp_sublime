#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;


void solve() {
  
  ll n;cin>>n;
  auto query=[&](ll i,ll j)->bool{
  	cout<<i<<" "<<j<<endl;
  	ll val ;cin>>val;
  	return val == 1;
  }	;

  
  for(ll j=1;j<=n-1;j++){
  	for(ll i=0;i<n-j;i++){
  		if(query(i+1,i+j+1))return;
  	}
  }

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