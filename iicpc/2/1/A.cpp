#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-12;


void solve() {
   	ll n,t,m,x,y;cin>>n>>t>>m>>x>>y;	
   	ld answer = (ld)(m/x) + (ld)(n-m)/y -t*60;
   	answer = ceil(answer/60);
   	answer = max(answer, (ld)0);
   	cout<<answer<<endl;
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