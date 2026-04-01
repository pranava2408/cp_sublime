#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve() {
 	ll n,q;cin>>n>>q;
 	priority_queue<ll,vector<ll>,greater<ll>> pq ;
	for(ll i=1;i<=n;i++){
		pq.push(i);
	}
	vector<ll> ct(n+1,1);
 	// vector<ll> cnt(n+2,0);
 	while(q--){
 		ll x,y;cin>>x>>y;
 		// cnt[x]++;
 		// cnt[y+1]--;
 		// auto it = 
 		// vector<ll> other;
 		ll cnt = 0;
 		bool ck = false;
 		if(ct[y]==0){
 			ck = true;
 		}
 		while(pq.size() && pq.top()<=x){
 			// auto it = temp.lower_bound(x);
 			// if(it==temp.end()||*it>y)break;
 			cnt+=ct[pq.top()];
 			ct[pq.top()]=0;
 			// other.push_back((*it)+1);
 			// temp.erase(it);
 			pq.pop();
 			// pq.push(y);
 		}
 		ct[y]+=cnt;
 		if(ck)pq.push(y);
 		// for(auto pos:other){
 		// 	temp.insert(pos+1);
 		// }
 		cout<<cnt<<endl;
 	}	
 	// ll sum =0 ;
 	// for(ll i=1;i<=n;i++){
 	// 	sum += cnt[i];
 	// 	cout<<sum<<" \n"[i==n];
 	// }
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