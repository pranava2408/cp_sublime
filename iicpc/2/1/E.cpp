#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;


void solve() {
  ll n,q ;cin>>n>>q;
  vector<ll> a(n);
  for(auto &pos:a)cin>>pos;
  sort(a.begin(),a.end());
  while(q--){
  	ll k;cin>>k;
  	ll answer =k-1;
  	ll low =0,high = n-1;
  	while(low<=high){
  		ll mid = (low+high)>>1;
  		ll left = a[mid]+1 -(mid+1);
  		ll need = k - left;
  		ll have = mid == n-1?1e18:a[mid+1]-a[mid]-1;
  		if(need<=0){
  			high = mid - 1;
  		}
  		else if(have>=need) {
  			answer = a[mid] + need;
  			break;
  		}
  		else{
  			low = mid + 1;
  		}

  	}
  	cout<<answer<<" ";
  }	
  cout<<endl;
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