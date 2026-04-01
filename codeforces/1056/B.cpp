#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;


void solve() {
  ll n, k;cin>>n>>k;
  ll cycle = n*n - k;
  if(cycle==1){
  	cout<<"NO"<<endl;
  	return;
  }	cout<<"YES"<<endl;
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<n;j++){
  		if(cycle==0){
  			cout<<'R';
  		}
  		else{
  			cycle --;
  			if(j==n-1||(cycle ==0 && i==0)){
  				cout<<'L';
  			}
  			else if(cycle==0){
  				cout<<'U';
  			}
  			else cout<<'R';
  		}
  	}
  	cout<<endl;
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